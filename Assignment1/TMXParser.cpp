#include "TMXParser.h"
#include <iostream>
#include "Error.h"

using namespace tinyxml2;

TMXParser::TMXParser(const char* filename)
{
	ParseXML(filename);
	LoadRects();
}

void TMXParser::ParseXML(const char* filename)
{
	XMLDocument doc;

	if (!(doc.LoadFile(filename) == XML_NO_ERROR))
	{
		Error::log(std::cout, doc.GetErrorStr1());
		return;
	}

	XMLElement* root = doc.FirstChildElement("map");
	if (root == nullptr)
	{
		Error::log(std::cout, "No root element");
		doc.Clear();
		return;
	}

	// Load map info from root
	m_tileHeight = atoi(root->Attribute("tilewidth"));
	m_tileWidth = atoi(root->Attribute("tileheight"));
	m_height = atoi(root->Attribute("height"));
	m_width = atoi(root->Attribute("width"));

	// Load image source
	XMLElement* elem = root->FirstChildElement("tileset");
	if (elem)
	{
		elem = elem->FirstChildElement("image");
		if (elem)
		{
			std::string file = "../res/";
			m_imageSource = (file.append(elem->Attribute("source")));

			m_imageWidth = atoi(elem->Attribute("width"));
			m_imageHeight = atoi(elem->Attribute("height"));
		}
	}

	// Look for gids
	elem = root->FirstChildElement("layer");
	if (elem)
	{
		elem = elem->FirstChildElement("data");
	}

	if (elem)
	{
		for (elem = elem->FirstChildElement("tile"); elem != nullptr; elem = elem->NextSiblingElement())
		{
			m_gid.push_back(atoi(elem->Attribute("gid")));
		}
	}

	doc.Clear();
}

void TMXParser::LoadRects()
{
	// Loop over source image filling in rects with associated gid index
	for (int y = 0; y + m_tileHeight <= m_imageHeight; y += m_tileHeight)
	{
		for (int x = 0; x + m_tileWidth <= m_imageWidth; x += m_tileWidth)
		{
			SDL_Rect rect;
			rect.w = m_tileWidth;
			rect.h = m_tileHeight;
			rect.x = x;
			rect.y = y;

			m_rects.push_back(rect);
		}
	}
}

SDL_Rect TMXParser::getRect(int x, int y)
{
	return m_rects[m_gid[m_width * y + x] - 1];
}
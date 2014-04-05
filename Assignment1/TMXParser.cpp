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
		tinyxml2::XMLElement* child = elem->FirstChildElement("image");
		if (child)
		{
			std::string file = "../res/tilesets/";
			m_imageSource = (file.append(child->Attribute("source")));

			m_imageWidth = atoi(child->Attribute("width"));
			m_imageHeight = atoi(child->Attribute("height"));
		}
	}

	m_numLayers = 0;

	// Look for gids
	for (elem = root->FirstChildElement("layer"); elem != nullptr; elem = elem->NextSiblingElement("layer"))
	{
		m_numLayers += 1;

		// vector holding tiles
		std::vector<int> gids;

		tinyxml2::XMLElement* child = elem->FirstChildElement("data");
		if (child)
		{
			for (child = child->FirstChildElement("tile"); child != nullptr; child = child->NextSiblingElement("tile"))
			{
				gids.push_back(atoi(child->Attribute("gid")));
			}
		}

		// add collection of tiles to the layer
		m_layers.push_back(gids);
	}	

	// Loop through blocked areas
	for (elem = root->FirstChildElement("objectgroup"); elem != nullptr; elem = elem->NextSiblingElement("objectgroup"))
	{
		if (strcmp(elem->Attribute("name"), "blocking") == 0)
		{
			tinyxml2::XMLElement* child;
			for (child = elem->FirstChildElement("object"); child != nullptr; child = child->NextSiblingElement("object"))
			{
				SDL_Rect rect = {
					atoi(child->Attribute("x")) / m_tileWidth,
					atoi(child->Attribute("y")) / m_tileHeight,
					atoi(child->Attribute("width")) / m_tileWidth,
					atoi(child->Attribute("height")) / m_tileHeight
				};

				m_blocked.push_back(rect);
			}
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

SDL_Rect* TMXParser::getRect(int x, int y, int layer)
{
	int index = m_layers[layer][m_width * y + x] - 1;
	if (index > 0)
		return &m_rects[m_layers[layer][m_width * y + x] - 1];
	else
		return nullptr;
}
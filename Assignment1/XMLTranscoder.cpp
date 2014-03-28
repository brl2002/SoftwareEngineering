#include "XMLTranscoder.h"

XMLTranscoder::XMLTranscoder()
{
	m_AnimSprites = std::vector<Animation*>();
}

XMLTranscoder::~XMLTranscoder()
{
	for (int i = 0; i < m_AnimSprites.size(); ++i)
	{
		delete m_AnimSprites[i];
	}

	m_AnimSprites.clear();
}

XMLTranscoder::XMLTranscoder(const XMLTranscoder& copy)
{
	this->m_AnimSprites = copy.m_AnimSprites;
}

XMLTranscoder& XMLTranscoder::operator=(const XMLTranscoder& other)
{
	this->m_AnimSprites = other.m_AnimSprites;

	return *this;
}

void XMLTranscoder::Transcode(const char* fileName)
{
	using namespace tinyxml2;

	//Load an XML file
	XMLDocument doc;
	doc.LoadFile(fileName);

	//Root element
	XMLElement* root = doc.RootElement();

	m_Width = atoi(root->Attribute("w"));
	m_Height = atoi(root->Attribute("h"));

	XMLElement* definitions = root->FirstChildElement();

	XMLElement* dir = definitions->FirstChildElement();

	for (XMLElement* anim = dir->FirstChildElement();
		anim; anim = anim->NextSiblingElement())
	{
		Animation* animSprite = new Animation();

		for (XMLElement* animFrame = anim->FirstChildElement();
			animFrame; animFrame = animFrame->NextSiblingElement())
		{
			//Attibutes: name, x, y, w, h
			int x = atoi(animFrame->Attribute("x"));
			int y = atoi(animFrame->Attribute("y"));
			int w = atoi(animFrame->Attribute("w"));
			int h = atoi(animFrame->Attribute("h"));

			FrameRect* frame = new FrameRect(x, y, w, h);
			animSprite->AddFrame(frame);
		}

		AddAnimSprite(animSprite);
	}

	//Dump loaded XML data
	doc.Clear();
}

void XMLTranscoder::AddAnimSprite(Animation* animSprite)
{
	m_AnimSprites.push_back(animSprite);
}

Animation* XMLTranscoder::GetAnimation(int index) const
{
	assert(index >= 0 && index < m_AnimSprites.size());

	return m_AnimSprites[index];
}

const int XMLTranscoder::TotalAnimations()
{
	return m_AnimSprites.size();
}

const int XMLTranscoder::TotalFrames(int animIndex)
{
	assert(animIndex >= 0 && animIndex < m_AnimSprites.size());

	return m_AnimSprites[animIndex]->TotalFrames();
}
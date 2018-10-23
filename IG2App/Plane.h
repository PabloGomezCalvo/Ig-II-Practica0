#pragma once

#include "Objects.h"
#include <OgreRenderTargetListener.h>

class PlaneObject: public Objects, public Ogre::RenderTargetListener
{
public:
	PlaneObject(Ogre::SceneNode* sPlane);
	virtual ~PlaneObject();
protected:
	Ogre::SceneNode* mPlane = nullptr;
	RenderTexture* renderTexture = nullptr;
	//Ogre::RenderTargetListener* mrender = nullptr;
};


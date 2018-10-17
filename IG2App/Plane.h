#pragma once

#include "Objects.h"
#include "RenderTargetListeners.h"

class PlaneObject: public Objects, public RenderTargetListeners
{
public:
	PlaneObject(Ogre::SceneNode* sPlane);
	virtual ~PlaneObject();
protected:
	Ogre::SceneNode* mPlane = nullptr;
	//Ogre::RenderTargetListener* mrender = nullptr;
};


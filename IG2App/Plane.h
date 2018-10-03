#pragma once

#include "Objects.h"
class PlaneObject: public Objects
{
public:
	PlaneObject(Ogre::SceneNode* sPlane);
	virtual ~PlaneObject();
protected:
	Ogre::SceneNode* mPlane = nullptr;
};


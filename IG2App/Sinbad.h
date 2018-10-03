#pragma once
#include "Objects.h"
class Sinbad:public Objects
{
public:
	Sinbad(Ogre::SceneNode* sSinbad);
	
	virtual ~Sinbad();
protected:
	Ogre::SceneNode* mSinbadNode = nullptr;
};


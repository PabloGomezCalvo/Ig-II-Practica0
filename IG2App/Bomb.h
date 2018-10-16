#pragma once
#include <Ogre.h>
#include "Objects.h"

class Bomb: public Objects
{
public:
	Bomb(Ogre::SceneNode* Bnode);
	Ogre::Entity* ent = nullptr;
	Ogre::SceneNode* mBomb = nullptr;
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	AnimationState * animationState = nullptr;
	~Bomb();
};


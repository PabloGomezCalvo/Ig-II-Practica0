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
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	virtual void receiveEvent(TipoEvent evnt) { psys->setEmitting(true); };
	AnimationState * animationState = nullptr;
	ParticleSystem* psys = nullptr;
	~Bomb();
};


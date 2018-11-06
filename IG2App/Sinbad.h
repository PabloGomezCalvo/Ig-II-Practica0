#pragma once
#include "Objects.h"
class Sinbad:public Objects
{
public:
	Sinbad(Ogre::SceneNode* sSinbad);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void receiveEvent(TipoEvent evnt) 
	{
		bomba = true;
		bomb();
	};

	Ogre::Entity* getEntity() {
		return ent;
	}
	void bomb();
	virtual ~Sinbad();
protected:
	Ogre::SceneNode* mSinbadNode = nullptr;
	AnimationState* animDance = nullptr;
	AnimationState* RunTopState = nullptr; //CORRER
	AnimationState* RunBaseState = nullptr; //CORRER EN LA BASE
	MovableObject* espadaR = nullptr;
	MovableObject* espadaL = nullptr;
	AnimationState * animationState = nullptr;
	AnimationState * eBomb = nullptr;
	bool correr = true;
	bool toyChocado = false;
	bool bomba = false;
	bool muerto = false;
	Ogre::Entity* ent = nullptr;


};


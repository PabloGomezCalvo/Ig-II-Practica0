#pragma once

#include "Objects.h"
class Toy: public Objects
{
public:
	Toy(Ogre::SceneNode* sToy);

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	Ogre::Entity* getEntity() {
		return eOmbligo;
	}

	~Toy();
protected:
	Ogre::SceneNode* mToyNode = nullptr;
	Ogre::SceneNode* cuello = nullptr;
	Ogre::SceneNode* cabeza = nullptr;
	Ogre::SceneNode* nariz = nullptr;
	Ogre::SceneNode* ombligo = nullptr;
	Ogre::SceneNode* cuerpo = nullptr;
	Ogre::Entity* eCuerpo = nullptr;
	Ogre::Entity* eOmbligo = nullptr;

	bool parado = true;

};


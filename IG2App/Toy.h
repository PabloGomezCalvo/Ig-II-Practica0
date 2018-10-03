#pragma once

#include "Objects.h"
class Toy: public Objects
{
public:
	Toy(Ogre::SceneNode* sToy);

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	~Toy();
protected:
	Ogre::SceneNode* mToyNode = nullptr;
	Ogre::SceneNode* cuello = nullptr;
	Ogre::SceneNode* cabeza = nullptr;
	Ogre::SceneNode* nariz = nullptr;
	Ogre::SceneNode* ombligo = nullptr;
	Ogre::SceneNode* cuerpo = nullptr;

	bool parado = true;

};


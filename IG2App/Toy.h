#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreInput.h>
class Toy: public OgreBites::InputListener
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


#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
class Toy
{
public:
	Toy(Ogre::SceneNode* sToy);
	~Toy();
protected:
	Ogre::SceneNode* mToyNode = nullptr;
	Ogre::SceneNode* cuello = nullptr;
	Ogre::SceneNode* cabeza = nullptr;
	Ogre::SceneNode* nariz = nullptr;
	Ogre::SceneNode* ombligo = nullptr;
	Ogre::SceneNode* cuerpo = nullptr;

};


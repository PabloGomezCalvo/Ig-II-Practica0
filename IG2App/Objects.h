#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
using namespace Ogre;
class Objects: public OgreBites::InputListener
{
public:
	Objects(Ogre::SceneNode* sSinbad) {};
	virtual ~Objects() {};
};






#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
using namespace Ogre;
enum TipoEvent { MUERTE, NORMAL };
class Objects: public OgreBites::InputListener
{
public:
	
	Objects(Ogre::SceneNode* sSinbad) {};
	virtual ~Objects() {};
	virtual void receiveEvent(TipoEvent evnt) {};
	static std::vector<Objects*>appListeners;
	static void addAppListener(Objects* s) {
		appListeners.push_back(s);
	}
	static void fireAppEvent(TipoEvent evento) {
		for (int i = 0; i < appListeners.size(); i++) {
			appListeners[i]->receiveEvent(evento);
		}
	}
	
};






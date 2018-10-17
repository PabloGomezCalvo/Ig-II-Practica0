#pragma once
#include <Ogre.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <OgreRenderTargetListener.h>

using namespace Ogre;

class RenderTargetListeners: public RenderTargetListener
{
public:
	RenderTargetListeners();
	virtual void preRenderTargetUpdate(const RenderTargetEvent& evt) {};//ocultar panel y restablecer luz
	virtual void postRenderTargetUpdate(const RenderTargetEvent& evt) {}; //restablecer los cambios
	virtual void preViewportUpdate(const RenderTargetViewportEvent& evt) {};
	virtual void postViewportUpdate(const RenderTargetViewportEvent& evt) {};
	virtual void viewportAdded(const RenderTargetViewportEvent& evt) {};
	virtual void viewportRemoved(const RenderTargetViewportEvent& evt) {};
	virtual ~RenderTargetListeners();
};


#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include "Toy.h"
#include "Sinbad.h"
#include "Plane.h"
#include "Bomb.h"
#include "Objects.h"

class IG2App : public  OgreBites::IG2ApplicationContext, OgreBites::InputListener 
{
public:
  explicit IG2App() : IG2ApplicationContext("IG2App") { };  // new -> setup()  
  virtual ~IG2App() { };   // delete -> shutdown()

 
protected:
  virtual void setup();
  virtual void shutdown();
  virtual void setupScene();
  virtual void frameRendered(const Ogre::FrameEvent& evt);
  virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
      
  Ogre::SceneManager* mSM = nullptr;
  OgreBites::TrayManager* mTrayMgr = nullptr;    
  Ogre::SceneNode* mLightNode = nullptr;
  Ogre::SceneNode* mCamNode = nullptr;
  Ogre::SceneNode* mSinbadNode = nullptr;
  Ogre::SceneNode* mPlaneNode = nullptr;
  Ogre::SceneNode* mToyNode = nullptr;
  Ogre::SceneNode* mBombNode = nullptr;
  Objects* toy;
  Objects* sinbad;
  Objects* plano;
  Objects* bomb;
  Objects* objetos;

  Viewport* vp = nullptr;

  OgreBites::CameraMan* mCamMgr = nullptr;

  bool interferencia = false;
  int milisegundos = 0;
  bool targetSinbad = false;

};

#endif

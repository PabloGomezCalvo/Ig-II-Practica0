#include "IG2App.h"
#include <iostream>



using namespace Ogre;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt)
{
  if (evt.keysym.sym == SDLK_ESCAPE)
  {
    getRoot()->queueEndRendering();
  }
  else if (evt.keysym.sym == SDLK_p) {
	  mPlaneNode->rotate(Ogre::Vector3(1, 0, 0), Ogre::Radian(3.14 / 4));
  }
  else if (evt.keysym.sym == SDLK_c) {
	  if(!targetSinbad)
	  mCamMgr->setTarget(mSinbadNode); 
	  else
		  mCamMgr->setTarget(mSinbadNode->getParentSceneNode());

	  targetSinbad = !targetSinbad;
  
  }

  else if (evt.keysym.sym == SDLK_i) {
	  CompositorManager::getSingleton().setCompositorEnabled(vp,
		  "Interference", true);
	  //interferencia = true;
	  //milisegundos = 0;
  }
  
  return true;
}

void IG2App::shutdown()
{
  mShaderGenerator->removeSceneManager(mSM);  
  mSM->removeRenderQueueListener(mOverlaySystem);  
					
  mRoot->destroySceneManager(mSM);  

  delete mTrayMgr;  mTrayMgr = nullptr;
  delete mCamMgr; mCamMgr = nullptr;
  
  // do not forget to call the base 
  IG2ApplicationContext::shutdown();
}

void IG2App::setup(void)
{
  // do not forget to call the base first
  IG2ApplicationContext::setup();

  mSM = mRoot->createSceneManager();  

  // register our scene with the RTSS
  mShaderGenerator->addSceneManager(mSM);

  mSM->addRenderQueueListener(mOverlaySystem);

  mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);  
  mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
  addInputListener(mTrayMgr);

  addInputListener(this);   
  setupScene();
}

void IG2App::setupScene(void)
{
  // create the camera
  Camera* cam = mSM->createCamera("Cam");
  cam->setNearClipDistance(1); 
  cam->setFarClipDistance(10000);
  cam->setAutoAspectRatio(true);
  //cam->setPolygonMode(Ogre::PM_WIREFRAME); 
  //camara para el reflejo
 


  mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
  mCamNode->attachObject(cam);
  

  mCamNode->setPosition(0, 0, 1000);
  mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
  //mCamNode->setDirection(Ogre::Vector3(0, 0, -1));  
  
  // and tell it to render into the main window
  vp = getRenderWindow()->addViewport(cam);
  //vp->setBackgroundColour(Ogre::ColourValue(1, 1, 1));

  //------------------------------------------------------------------------

  // without light we would just get a black screen 

  Light* luz = mSM->createLight("Luz");
  luz->setType(Ogre::Light::LT_DIRECTIONAL);
  luz->setDiffuseColour(0.75, 0.75, 0.75);

  //mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
  mLightNode = mCamNode->createChildSceneNode("nLuz");
  mLightNode->attachObject(luz);

  mLightNode->setDirection(Ogre::Vector3(0, 0, -1));  //vec3.normalise();
  //lightNode->setPosition(0, 0, 1000);
 
  //------------------------------------------------------------------------

  


  

  //------------------------------------------------------------------------

  mCamMgr = new OgreBites::CameraMan(mCamNode);
  addInputListener(mCamMgr);
  mCamMgr->setStyle(OgreBites::CS_ORBIT);  
  
  //mCamMgr->setTarget(mSinbadNode);  
  //mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

  //------------------------------------------------------------------------

  mPlaneNode = mSM->getRootSceneNode()->createChildSceneNode("nPlane");
  
  plano = new PlaneObject(mPlaneNode);
  


  mToyNode = mPlaneNode->createChildSceneNode("Toy");
  toy = new Toy(mToyNode);

  
  mSinbadNode = mPlaneNode->createChildSceneNode("Sinbad");

  sinbad = new Sinbad(mSinbadNode);

  addInputListener(sinbad);
  

  addInputListener(toy);


  mBombNode = mPlaneNode->createChildSceneNode("nBomb");
  bomb = new Bomb(mBombNode);

  addInputListener(bomb);
   
  /*mSM->setSkyPlane(true, Plane(Vector3::UNIT_Z, -20),
	  "IG2App/ejemploShadersLM", 1, 1, true, 0.0, 100, 100);

	  */
  mSM->setSkyPlane(true, Plane(Vector3::UNIT_Z, -20),
	  "mandelbrot1", 1, 1, true, 0.0, 100, 100);

	  
  
  //-------------------------------------------------------------------------

  CompositorManager::getSingleton().addCompositor(vp,
	  "Luminance");
  CompositorManager::getSingleton().setCompositorEnabled(vp,
	  "Luminance", false);

  CompositorManager::getSingleton().addCompositor(vp,
	  "Interference");
  CompositorManager::getSingleton().setCompositorEnabled(vp,
	  "Interference", false); /*	  if (interferencia) {
		  milisegundos++;
		  std::cout << milisegundos << std::endl;
		  if (milisegundos == 500) {
			  CompositorManager::getSingleton().setCompositorEnabled(vp,
				  "Interference", false);
			  interferencia = false;
		  }
	  }
  */

}


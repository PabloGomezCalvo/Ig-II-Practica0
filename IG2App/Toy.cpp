#include "Toy.h"
#include <Ogre.h>


Toy::Toy(Ogre::SceneNode* sToy): Objects(sToy)
{
	//mToyNode = sToy->getCreator()->getSceneNode("nPlane")->createChildSceneNode("nToy");

	cuello = sToy;
	cuello->setPosition(300, 100, 0);
	cuello->rotate(Ogre::Vector3(0.0f, 1.0f, 0.0f), Ogre::Radian(3.14));
	cuello->showBoundingBox(true);
	
	

	cabeza = cuello->createChildSceneNode("nCabeza");
	Ogre::Entity* eCabeza = cuello->getCreator()->createEntity("uv_sphere.mesh");
	cabeza->attachObject(eCabeza);
	
	cabeza->setPosition(0, 150, 0);
	cabeza->setScale(0.6, 0.6, 0.6);
	eCabeza->setMaterialName("toy");

	nariz = cabeza->createChildSceneNode("nNariz"); 
	Ogre::Entity* eNariz = cuello->getCreator()->createEntity("uv_sphere.mesh");
	nariz->attachObject(eNariz);

	nariz->setPosition(0, 0, -100);
	nariz->setScale(0.1, 0.1, 0.1);

	cuerpo = cuello->createChildSceneNode("nCuerpo");
	eCuerpo = cuello->getCreator()->createEntity("uv_sphere.mesh");
	cuerpo->attachObject(eCuerpo);
	eCuerpo->setMaterialName("toy");
	//cuerpo->showBoundingBox(true);
	
	


	ombligo = cuerpo->createChildSceneNode("nOmbligo");
	eOmbligo = cuello->getCreator()->createEntity("sphere.mesh");
	ombligo->attachObject(eOmbligo);

	ombligo->setPosition(0, 0, -100);
	ombligo->setScale(0.1, 0.1, 0.1);

	
	

}
void Toy::frameRendered(const Ogre::FrameEvent& evt) {

	if (eOmbligo->getWorldBoundingSphere().intersects(cuello->getCreator()->getEntity("Bomb")->getBoundingBox())) {
		fireAppEvent(TipoEvent::MUERTE);
		cuello->setVisible(false);
	}
	else {

		if (!parado) {

			cuello->translate(0, 0, 30 * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
			cuerpo->rotate(Ogre::Vector3(30 * evt.timeSinceLastFrame, 0, 0), Ogre::Radian(0.05f));
			cabeza->rotate(Ogre::Vector3(0, 30 * evt.timeSinceLastFrame, 0), Ogre::Radian(0.01f));
		}

	}

}


bool Toy::keyPressed(const OgreBites::KeyboardEvent & evt)
{
	switch(evt.keysym.sym)
	{
	case SDLK_t:
		
		//cuello->setPosition(cuello->getPosition().x + cuello->getOrientation().x, cuello->getPosition().y, cuello->getPosition().z + cuello->getOrientation().z);
		cuello->translate(0,0,1, Ogre::Node::TS_LOCAL);
		cuerpo->rotate(Ogre::Vector3(1, 0, 0), Ogre::Radian(0.05f));
		cabeza->rotate(Ogre::Vector3(0, 1, 0), Ogre::Radian(0.01f));
	
		

		break;
	case SDLK_y:

		if (!parado)
			parado = true;
		else parado = false;

		break;

	case SDLK_v:

		cuello->rotate(Ogre::Vector3(0, 1, 0), Ogre::Radian(3.14/4));

		break;
	}
	return false;
}

Toy::~Toy()
{
}

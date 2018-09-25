#include "Toy.h"



Toy::Toy(Ogre::SceneNode* sToy)
{
	//mToyNode = sToy->getCreator()->getSceneNode("nPlane")->createChildSceneNode("nToy");

	cuello = sToy;
	cuello->setPosition(0, 100, 0);
	

	cabeza = cuello->createChildSceneNode("nCabeza");
	Ogre::Entity* eCabeza = cuello->getCreator()->createEntity("sphere.mesh");
	cabeza->attachObject(eCabeza);

	cabeza->setPosition(0, 150, 0);
	cabeza->setScale(0.6, 0.6, 0.6);


	nariz = cabeza->createChildSceneNode("nNariz"); 
	Ogre::Entity* eNariz = cuello->getCreator()->createEntity("sphere.mesh");
	nariz->attachObject(eNariz);

	nariz->setPosition(0, 0, -100);
	nariz->setScale(0.1, 0.1, 0.1);

	cuerpo = cuello->createChildSceneNode("nCuerpo");
	Ogre::Entity* eCuerpo = cuello->getCreator()->createEntity("sphere.mesh");
	cuerpo->attachObject(eCuerpo);



	ombligo = cuerpo->createChildSceneNode("nOmbligo");
	Ogre::Entity* eOmbligo = cuello->getCreator()->createEntity("sphere.mesh");
	ombligo->attachObject(eOmbligo);

	ombligo->setPosition(0, 0, -100);
	ombligo->setScale(0.1, 0.1, 0.1);




}


Toy::~Toy()
{
}

#include "Sinbad.h"



Sinbad::Sinbad(Ogre::SceneNode* sSinbad): Objects(sSinbad)
{
	mSinbadNode = sSinbad;
	Ogre::Entity* ent = mSinbadNode->getCreator()->createEntity("Sinbad.mesh");

	mSinbadNode->attachObject(ent);


	mSinbadNode->setPosition(400, 100, -300);
	mSinbadNode->setScale(20, 20, 20);
	mSinbadNode->yaw(Ogre::Degree(-45));
	mSinbadNode->showBoundingBox(true);
	//mSinbadNode->setVisible(false);
}


Sinbad::~Sinbad()
{
}

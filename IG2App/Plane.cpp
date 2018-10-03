#include "Plane.h"



PlaneObject::PlaneObject(Ogre::SceneNode* sPlane): Objects(sPlane)
{
	mPlane = sPlane;
	MeshManager::getSingleton().createPlane(("mPlane1080x800"),
		(ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME),
		Plane(Plane(Vector3::UNIT_Y, 0)), (1080), (800),
		(100), (80), (true),
		(1), (1.0), (1.0), (Vector3::UNIT_Z));

	Ogre::Entity* ent1 = mPlane->getCreator()->createEntity("mPlane1080x800");


	mPlane->attachObject(ent1);

	ent1->setMaterialName("IG2App/plano");
}


PlaneObject::~PlaneObject()
{
}

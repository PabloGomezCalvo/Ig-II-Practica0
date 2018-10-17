#include "Plane.h"
#include <Ogre.h>



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

	//Reflejo
	
	//Camera* camRef = mPlane->getCreator()->createCamera("RefCam");
	//camRef->setNearClipDistance(1);
	//camRef->setFarClipDistance(10000);
	//camRef->setAutoAspectRatio(true);
	//mPlane->getCreator()->getSceneNode("nCam")->attachObject(camRef);
	//

	//MovablePlane* mp = new MovablePlane("Plane");
	//mPlane->attachObject(mp);
	//camRef->enableReflection(mp);
	//camRef->enableCustomNearClipPlane(mp);

	//
	//TexturePtr rttTex = TextureManager::getSingleton().createManual(
	//	"texRtt", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	//	TEX_TYPE_2D, (Real)camRef->getViewport()->getActualWidth(),
	//	(Real)camRef->getViewport()->getActualHeight(),
	//	0, PF_R8G8B8, TU_RENDERTARGET);	//RenderTexture* renderTexture = rttTex->getBuffer()->getRenderTarget();
	//Viewport * vpt = renderTexture->addViewport(camRef);
	//vpt->setClearEveryFrame(true);
	//vpt->setBackgroundColour(ColourValue::Black);	//	//TextureUnitState* tu = ent1->getSubEntities[0]->getMaterial()->
	//	getTechniques[0]->getPasses[0]->
	//	createTextureUnitState("texRtt");
	//tu->setColourOperation(LBO_MODULATE);
	//tu->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
	//tu->setProjectiveTexturing(true, mPlane->getCreator()->getCamera("RefCam"));
	

	
}


PlaneObject::~PlaneObject()
{
}

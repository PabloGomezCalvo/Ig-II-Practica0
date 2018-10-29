#include "Sinbad.h"
#include <iostream>
#include <Ogre.h>


Sinbad::Sinbad(Ogre::SceneNode* sSinbad): Objects(sSinbad)
{
	mSinbadNode = sSinbad;
	Ogre::Entity* ent = mSinbadNode->getCreator()->createEntity("Sinbad.mesh");

	mSinbadNode->attachObject(ent);


	mSinbadNode->setPosition(400, 100, -300);
	mSinbadNode->setScale(20, 20, 20);
	mSinbadNode->yaw(Ogre::Degree(-45));
	mSinbadNode->showBoundingBox(true);
	mSinbadNode->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
	mSinbadNode->setInitialState();

	//mSinbadNode->setVisible(false);

	AnimationStateSet * aux = ent->getAllAnimationStates();
	auto it = aux->getAnimationStateIterator().begin();
	std::cout << "Animaciones de Sinbad:" << std::endl;
	while (it != aux->getAnimationStateIterator().end()) { auto s = it->first; std::cout << s << std::endl; ++it; }
	std::cout << "--------------------------------------------" << std::endl;

	auto skeleton = ent->getMesh()->getSkeleton(); // entity -> getMesh()
	auto numBones = skeleton->getNumBones();
	for (auto i = 0; i < numBones; i++) { std::cout<<skeleton->getBone(i)->getName() << std::endl; }


	espadaL = mSinbadNode->getCreator()->createEntity("espadaL", "Sword.mesh");
	ent->attachObjectToBone("Sheath.L", espadaL);

	espadaR = mSinbadNode->getCreator()->createEntity("espadaR", "Sword.mesh");
	ent->attachObjectToBone("Handle.R", espadaR);

	animDance = ent->getAnimationState("Dance");
	animDance->setEnabled(true);
	animDance->setLoop(true);

	RunTopState = ent->getAnimationState("RunTop");
	RunTopState->setLoop(true);
	RunTopState->setEnabled(false);

	RunBaseState = ent->getAnimationState("RunBase");
	RunBaseState->setLoop(true);
	RunBaseState->setEnabled(false);
	int duracion = 15;
	Animation* animation = mSinbadNode->getCreator()->createAnimation("correr", duracion);
	animation->setInterpolationMode(Ogre::Animation::IM_LINEAR);
	NodeAnimationTrack * track = animation->createNodeTrack(0);
	track->setAssociatedNode(mSinbadNode);
	Vector3 keyframePosini(0, 0, 0);
	/*Vector3 dest(0.5, 0, 0.5);
	Vector3 src(mSinbadNode->getPosition());
	Ogre::Quaternion quat = src.getRotationTo(dest);*/
	Real longitudPaso = duracion / 4.0;
	TransformKeyFrame * kf;
	TransformKeyFrame * kfRot;

	//kf0
	kf = track->createNodeKeyFrame(0);
	kf->setTranslate(keyframePosini);



	//kf1
	kf = track->createNodeKeyFrame(longitudPaso * 1); // Keyframe 1: arriba
	keyframePosini += Ogre::Vector3::UNIT_Z * 550.0;
	//mSinbadNode->setOrientation(Ogre::Quaternion(0.5, 0, -0.5, 0));
	kf->setTranslate(keyframePosini); // Arriba
	//kf->setRotation(quat);



	//kf2

	kf = track->createNodeKeyFrame(longitudPaso * 2);
	keyframePosini += Ogre::Vector3::UNIT_X * -800.0;

	//kf->setRotation(Ogre::Quaternion(0.5, 0, -0.5, 0));
	kf->setTranslate(keyframePosini);

	//kf3

	kf = track->createNodeKeyFrame(longitudPaso * 3);
	keyframePosini += Ogre::Vector3::UNIT_Z * -550.0;
	kf->setTranslate(keyframePosini);

	//kf4

	kf = track->createNodeKeyFrame(longitudPaso * 4);
	keyframePosini += Ogre::Vector3::UNIT_X * 800.0;
	kf->setTranslate(keyframePosini);

	animationState = mSinbadNode->getCreator()->createAnimationState("correr");
	animationState->setLoop(true);
	animationState->setEnabled(true);


}

void Sinbad::frameRendered(const Ogre::FrameEvent& evt) {
	animDance->addTime(evt.timeSinceLastFrame);
	RunBaseState->addTime(evt.timeSinceLastFrame);
	animationState->addTime(evt.timeSinceLastFrame);

}

bool Sinbad::keyPressed(const OgreBites::KeyboardEvent& evt) {

	switch (evt.keysym.sym)
	{
	case SDLK_r:
		if (!correr) {
			animDance->setEnabled(false);
			RunBaseState->setEnabled(true);
			correr = true;
	}
		else {
			animDance->setEnabled(true);
			RunBaseState->setEnabled(false);
			correr = false;

	}
		break;


	default:
		break;
	}
	return true;
}
	


Sinbad::~Sinbad()
{
}

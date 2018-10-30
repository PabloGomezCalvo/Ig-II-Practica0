#include "Sinbad.h"
#include <iostream>
#include <Ogre.h>


Sinbad::Sinbad(Ogre::SceneNode* sSinbad): Objects(sSinbad)
{
	mSinbadNode = sSinbad;
	Ogre::Entity* ent = mSinbadNode->getCreator()->createEntity("Sinbad.mesh");

	mSinbadNode->attachObject(ent);

	
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
	int duracion = 24;
	Animation* animation = mSinbadNode->getCreator()->createAnimation("correr", duracion);
	animation->setInterpolationMode(Ogre::Animation::IM_LINEAR);
	NodeAnimationTrack * track = animation->createNodeTrack(0);
	track->setAssociatedNode(mSinbadNode);
	Vector3 keyframePosini(400, 100, -300);
	
	Real longitudPaso = 20 / 4.0;
	Real longitudRot = 4 / 4;
	Real pasoActual = 0;
	TransformKeyFrame * kf;
	

	//kf0
	kf = track->createNodeKeyFrame(0);
	kf->setTranslate(keyframePosini);



	//kf1
	pasoActual += longitudPaso;
	kf = track->createNodeKeyFrame(pasoActual); // Keyframe 1: arriba
	keyframePosini += Ogre::Vector3::UNIT_Z * 550.0;
	kf->setTranslate(keyframePosini); // Arriba
	
	//kf2
	pasoActual += longitudRot;
	kf = track->createNodeKeyFrame(pasoActual);
	kf->setRotation(Ogre::Quaternion(Degree(-90), Vector3(0,1,0)));
	kf->setTranslate(keyframePosini);

	//kf3
	pasoActual += longitudPaso;
	kf = track->createNodeKeyFrame(pasoActual);
	kf->setRotation(Quaternion(Degree(-90), Vector3(0, 1, 0)));
	keyframePosini += Ogre::Vector3::UNIT_X * -800.0;
	kf->setTranslate(keyframePosini);

	//kf4
	pasoActual += longitudRot;
	kf = track->createNodeKeyFrame(pasoActual);
	kf->setRotation(Quaternion(Degree(180), Vector3(0, 1, 0)));
	kf->setTranslate(keyframePosini);

	//KF5
	pasoActual += longitudPaso;
	kf = track->createNodeKeyFrame(pasoActual);
	keyframePosini += Ogre::Vector3::UNIT_Z * -550.0;
	kf->setRotation(Quaternion(Degree(180), Vector3(0, 1, 0)));
	kf->setTranslate(keyframePosini);
	//KF6
	pasoActual += longitudRot;
	kf = track->createNodeKeyFrame(pasoActual);
	kf->setRotation(Quaternion(Degree(90), Vector3(0, 1, 0)));
	kf->setTranslate(keyframePosini);
	//KF7
	pasoActual += longitudPaso;
	kf = track->createNodeKeyFrame(pasoActual);
	keyframePosini += Ogre::Vector3::UNIT_X * 800.0;
	kf->setRotation(Quaternion(Degree(90), Vector3(0, 1, 0)));
	kf->setTranslate(keyframePosini);
	//KF8
	pasoActual += longitudRot;
	kf = track->createNodeKeyFrame(pasoActual);
	kf->setRotation(Quaternion(Degree(0), Vector3(0, 1, 0)));
	kf->setTranslate(keyframePosini);

	animationState = mSinbadNode->getCreator()->createAnimationState("correr");
	animationState->setLoop(true);
	animationState->setEnabled(true);


}

void Sinbad::frameRendered(const Ogre::FrameEvent& evt) {
	if (!bomba) {
		animDance->addTime(evt.timeSinceLastFrame);
		RunBaseState->addTime(evt.timeSinceLastFrame);
		animationState->addTime(evt.timeSinceLastFrame);
		RunTopState->addTime(evt.timeSinceLastFrame);
		std::cout << mSinbadNode->getPosition() << std::endl;
	}
	else {
		eBomb->addTime(evt.timeSinceLastFrame);
		std::cout << mSinbadNode->getPosition() << std::endl;


	}

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
	case SDLK_b:
	{
		bomba = true;
		
		Quaternion antes = mSinbadNode->getOrientation();
		mSinbadNode->lookAt(Vector3(mSinbadNode->getCreator()->getSceneNode("nBomb")->getPosition().x, mSinbadNode->getPosition().y, mSinbadNode->getCreator()->getSceneNode("nBomb")->getPosition().z),
			Node::TS_WORLD
		);
		mSinbadNode->rotate(Quaternion(Degree(180), Vector3::UNIT_Y));
		Quaternion despues = mSinbadNode->getOrientation();

		mSinbadNode->setOrientation(antes);


		Real duracion = 8;
		Animation * animationBomb = mSinbadNode->getCreator()->createAnimation("animSinbadBomb", duracion);
		NodeAnimationTrack * track = animationBomb->createNodeTrack(0);
		track->setAssociatedNode(mSinbadNode->getCreator()->getSceneNode("Sinbad"));

		Vector3 keyframePos(mSinbadNode->getPosition());
		TransformKeyFrame * kf;

		kf = track->createNodeKeyFrame(0);
		kf->setRotation(antes);
		kf->setTranslate(mSinbadNode->getPosition());

		kf = track->createNodeKeyFrame(duracion / 2);

		Vector3 mDirection = mSinbadNode->getCreator()->getSceneNode("nBomb")->getPosition() - mSinbadNode->getPosition();

		Ogre::Vector3 src = mSinbadNode->getOrientation() * Ogre::Vector3::UNIT_X;
		Ogre::Quaternion quat = src.getRotationTo(mDirection, mSinbadNode->getOrientation().yAxis());
		kf->setRotation(despues);
		kf->setTranslate(mSinbadNode->getPosition());

		kf = track->createNodeKeyFrame(duracion);
		kf->setRotation(mSinbadNode->getOrientation());
		kf->setRotation(despues);
		kf->setTranslate(Vector3(mSinbadNode->getCreator()->getSceneNode("nBomb")->getPosition()));

		eBomb = mSinbadNode->getCreator()->createAnimationState("animSinbadBomb");
		eBomb->setLoop(false);
		eBomb->setEnabled(true);
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

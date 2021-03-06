#include "Bomb.h"



Bomb::Bomb(Ogre::SceneNode* Bnode) : Objects(Bnode)
{
	addAppListener(this);
	mBomb = Bnode;
	ent = mBomb->getCreator()->createEntity("Bomb", "uv_sphere.mesh");
	mBomb->showBoundingBox(true);
	mBomb->scale(Vector3(0.3, 0.3, 0.3));
	mBomb->attachObject(ent);
	mBomb->setPosition(Vector3(0, 25, 0));
	ent->setMaterialName("toy");
	mBomb->setInitialState();

	psys = mBomb->getCreator()->createParticleSystem("parSys", "Smoke");
	mBomb->attachObject(psys);
	psys->setEmitting(false);
	
	int duracion = 4;
	Animation* animation = mBomb->getCreator()->createAnimation("animacionvaiven", duracion);
	animation->setInterpolationMode(Ogre::Animation::IM_SPLINE);
	NodeAnimationTrack * track = animation->createNodeTrack(0);
	track->setAssociatedNode(mBomb);
	Vector3 keyframePosini(0,25,0);
	Vector3 keyframePosAr(0, 50, 0);
	Vector3 keyframePosAb(0, 0, 0);
	Real longitudPaso = duracion / 4.0;
	TransformKeyFrame * kf;

	//kf0
	kf = track->createNodeKeyFrame(0);
	kf->setTranslate(keyframePosini);
	
	//kf1
	kf = track->createNodeKeyFrame(longitudPaso * 1); // Keyframe 1: arriba
	kf->setTranslate(keyframePosAr); // Arriba
	//kf2

	kf = track->createNodeKeyFrame(longitudPaso * 2);
	kf->setTranslate(keyframePosini);

	//kf3

	kf = track->createNodeKeyFrame(longitudPaso * 3);
	kf->setTranslate(keyframePosAb);

	//kf4

	kf = track->createNodeKeyFrame(longitudPaso * 4);
	kf->setTranslate(keyframePosini);


	
	animationState = mBomb->getCreator()->createAnimationState("animacionvaiven");
	animationState->setLoop(true);
	animationState->setEnabled(true);

}


void Bomb::frameRendered(const Ogre::FrameEvent& evt) {
	animationState->addTime(evt.timeSinceLastFrame);
	psys->getEmitter(0)->setPosition(mBomb->getPosition());

};

bool Bomb::keyPressed(const OgreBites::KeyboardEvent& evt) {
	switch (evt.keysym.sym)
	{
	case SDLK_b:
		psys->setEmitting(true);
		break;
	default:
		break;
	}
	return true;
}

Bomb::~Bomb()
{
}

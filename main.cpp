#include <iostream>
#include <irrlicht.h>


#include "BallOnPlateEventReceiver.h"


using namespace BallOnPlate;



int main(){

	// create device and exit if creation failed

    BallOnPlateEventReceiver* newBallOnPlate = new BallOnPlateEventReceiver();

    newBallOnPlate->getDevice()->setEventReceiver(newBallOnPlate);

    newBallOnPlate->getBallOnPlate3DVisual()->run3D();

    delete newBallOnPlate;

    return 0;
}



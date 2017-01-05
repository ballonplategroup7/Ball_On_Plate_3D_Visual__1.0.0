/**
 * Ball
 *
 * File:   Ball.cpp
 *
 * Description:
 *
 *  Class for Ball.
 *  Ball have:
 *      - ISceneNode Object
 *      - Current X
 *      - Current Y
 *      - Previous X
 *      - Previous Y
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#include "Ball.h"
#include <math.h>       /* cos */

#include <iostream>

 namespace
{
    /**
     * For Constant Variables
     *
     */
    const static int OUT_OF_SYSTEM=-1453; //  Constant variable which have value out of system.
    const static int DEFAULT_CURRENT_X=OUT_OF_SYSTEM;
    const static int DEFAULT_CURRENT_Y=OUT_OF_SYSTEM;
    const static int DEFAULT_PREVIOUS_X=OUT_OF_SYSTEM;
    const static int DEFAULT_PREVIOUS_Y=OUT_OF_SYSTEM;
}

namespace BallOnPlate
{
    /**
     * One Parameter Constructor
     *
     * Call:
     *  - setDevice
     *  - createBall
     *  - setCurrentX
     *  - setCurrentY
     *  - setPreviousX
     *  - setPreviousY
     *
     *  @param newDevice
     */
    Ball::Ball(IrrlichtDevice* newDevice, ISceneNode* parentNode)
    {
        setDevice(newDevice);
        createBall(parentNode);
        setCurrentX(DEFAULT_CURRENT_X);
        setCurrentY(DEFAULT_CURRENT_Y);
        setPreviousX(DEFAULT_PREVIOUS_X);
        setPreviousY(DEFAULT_PREVIOUS_Y);
    }

    /**
     * Create Ball
     */
    void Ball::createBall(ISceneNode* parentNode)
    {
        ballSceneNode = getSceneManager()->addSphereSceneNode(1.3f,32,0, 0,
                             vector3df(0, 6.0f, 0),//position
                             vector3df(0, 0, 0),//rotation
                             vector3df(9.0f, 9.0f, 9.0f));//scale

        ballSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

        ballSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/stell.jpg") );

        //ballSceneNode->setParent(parentNode);
    }

    /**
     * Update Ball Position
     *
     * @param plate
     */
    void Ball::update(Plate *plate)
    {
        /** Plate Rotation */
        core::vector3df plateRotation = plate->getPlate()->getRotation();
        /** Ball Rotation */
        core::vector3df ballPosition = getBall()->getPosition();

        /**
            Normally :

                ballPosition.X =  -getCurrentY();
                ballPosition.Z =  getCurrentX();
        */
        ballPosition.X =  +getCurrentY();
        ballPosition.Z =  -getCurrentX();

        /** Angle Calculate */
        double angleFirstPlateRotationX,angleSecondPlateRotationX,angleFirstValuePlateRotationX,angleSecondValuePlateRotationX,
        angleFirstPlateRotationZ,angleSecondPlateRotationZ,angleFirstValuePlateRotationZ,angleSecondValuePlateRotationZ;

        /** Calculate Angles For X */
        angleFirstPlateRotationX = -plateRotation.X;
        angleSecondPlateRotationX = 90+plateRotation.X;
        angleFirstValuePlateRotationX = cos ( angleFirstPlateRotationX * PI / 180.0 );
        angleSecondValuePlateRotationX  = cos ( angleSecondPlateRotationX * PI / 180.0 );
        angleFirstPlateRotationZ = plateRotation.Z;

        /** Calculate Angles For Z */
        angleFirstPlateRotationZ = plateRotation.Z;
        angleSecondPlateRotationZ = 90-plateRotation.Z;
        angleFirstValuePlateRotationZ = cos ( angleFirstPlateRotationZ * PI / 180.0 );
        angleSecondValuePlateRotationZ  = cos ( angleSecondPlateRotationZ * PI / 180.0 );

        /** Calculate For Ball Position Y */
        ballPosition.Y = ballPosition.X * angleSecondValuePlateRotationZ / angleFirstValuePlateRotationZ ;
        ballPosition.Y += ballPosition.Z * angleSecondValuePlateRotationX / angleFirstValuePlateRotationX ;
        ballPosition.Y +=(15.0f);

        /**  Set it for ball */
        getBall()->setPosition(ballPosition);
    }
}

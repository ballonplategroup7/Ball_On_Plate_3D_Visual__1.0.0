/**
 * Plate
 *
 * File:   Plate.cpp
 *
 * Description:
 *
 *  Class for Plate.
 *  Plate have:
 *      - ISceneNode Object
 *      - Angle X
 *      - Angle Y
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#include "Plate.h"

 namespace
{
    /**
     * For Constant Variables
     *
     */
    const static int DEFAULT_VALUE_ANGLE_X=0;
    const static int DEFAULT_VALUE_ANGLE_Y=0;
}

namespace BallOnPlate
{

    /**
     * One Parameter Constructor
     *
     * Call:
     *  - setDevice
     *  - createPlate
     *  - setAngleX
     *  - setAngleY
     *
     *  @param newDevice
     */
    Plate::Plate(IrrlichtDevice* newDevice,ISceneNode* parentNode,double a1,double a2,double a3,
                                                    double p1,double p2,double p3,
                                                   double r1,double r2,double r3,
                                                   double s1,double s2,double s3,ITexture* fileName)
    {
        setDevice(newDevice);
        createPlate(parentNode, a1,a2,a3,p1, p2, p3, r1, r2, r3, s1, s2, s3, fileName);
        setAngleX(DEFAULT_VALUE_ANGLE_X);
        setAngleY(DEFAULT_VALUE_ANGLE_Y);
    }

    /**
     * Create Plate
     */
    void Plate::createPlate(ISceneNode* parentNode,double a1,double a2,double a3,
                                                    double p1,double p2,double p3,
                                                   double r1,double r2,double r3,
                                                   double s1,double s2,double s3,ITexture* fileName){

        plateSceneNode = getSceneManager()->addCubeSceneNode(a1,0,0,
                            vector3df(p1, p2, p3),//position
                            vector3df(r1, r2, r3),//rotation
                            vector3df(s1, s2, s3)); //scale

        plateSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

        plateSceneNode->setMaterialTexture( 0, fileName );

        //  plateSceneNode->setParent(parentNode);
    }

    /**
    * Update Ball Rotate
    */
     void Plate::update( ISceneNode* servoMotorXStick, ISceneNode* servoMotorYStick,
                        int servoMotorXStickXPosition, int servoMotorXStickYPosition,
                        int servoMotorYStickXPosition, int servoMotorYStickYPosition){

        /**
         * use Angle X plateRotation.X
         * use Angle Y plateRotation.Y
         */

        /**
            Normally :

                core::vector3df plateRotation =  getPlate()->getRotation();
                plateRotation.X = -getAngleX()/10;
                plateRotation.Z = getAngleY()/10;
                getPlate()->setRotation(plateRotation);



                core::vector3df PositionStickX =  servoMotorXStick->getPosition();

                PositionStickX.Y = PositionStick.Y + getAngleX()/7;
                PositionStickX.X = PositionStick.X - getAngleY()/7;

                servoMotorXStick->setPosition(PositionStickX);




                core::vector3df PositionStickY =  servoMotorXStick->getPosition();

                PositionStickY.Y = PositionStick.Y - getAngleX()/7;
                PositionStickY.X = PositionStick.X + getAngleY()/7;

                servoMotorYStick->setPosition(PositionStickY);

 *//*
               core::vector3df plateRotation =  getPlate()->getRotation();
                plateRotation.X = getAngleX()/10;
                plateRotation.Z = -getAngleY()/10;
                getPlate()->setRotation(plateRotation);

                core::vector3df PositionStickX =  servoMotorXStick->getPosition();

                PositionStickX.Y = servoMotorXStickYPosition  - getAngleX()/3;
                PositionStickX.X = servoMotorXStickXPosition - getAngleX()/3;

                servoMotorXStick->setPosition(PositionStickX);

                core::vector3df PositionStickY =  servoMotorYStick->getPosition();

                PositionStickY.Y =  servoMotorYStickYPosition  - getAngleY()/3;
                PositionStickY.X =  servoMotorYStickXPosition - getAngleY()/3;

                servoMotorYStick->setPosition(PositionStickY);
*/
    }
}

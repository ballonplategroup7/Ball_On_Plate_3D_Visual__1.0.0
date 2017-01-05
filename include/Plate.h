/**
 * Plate
 *
 * File:   Plate.h
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

#ifndef PLATE_H
#define PLATE_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace BallOnPlate
{
    class Plate
    {
        public:

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
            Plate(IrrlichtDevice* newDevice,ISceneNode* parentNode,double a1,double a2,double a3,
                                                    double p1,double p2,double p3,
                                                   double r1,double r2,double r3,
                                                   double s1,double s2,double s3,ITexture* fileName);

            /**
            * Update Plate Rotate
            */
            void update( ISceneNode* servoMotorXStick, ISceneNode* servoMotorYStick,
                        int servoMotorXStickXPosition, int servoMotorXStickYPosition,
                        int servoMotorYStickXPosition, int servoMotorYStickYPosition);

            /**
             * Set Irrlicht Device
             */
            void setDevice(IrrlichtDevice* newDevice){device = newDevice;}

            /**
             * Get Irrlicht Device
             */
            IrrlichtDevice* getDevice(){return device;}

            /**
             * Get Scene Manager
             */
            ISceneManager* getSceneManager(){return getDevice()->getSceneManager();}

            /**
             * Get Video Driver
             */
            IVideoDriver* getVideoDriver(){return getDevice()->getVideoDriver();}

            /**
             * Create Plate
             */
            void createPlate(ISceneNode* parentNode,double a1,double a2,double a3,
                                                    double p1,double p2,double p3,
                                                   double r1,double r2,double r3,
                                                   double s1,double s2,double s3,ITexture* fileName);

            /**
             * Get Plate
             */
            ISceneNode* getPlate(){return plateSceneNode;}

            /**
             * Get Plate Angle X
             *
             * @return Plate Angle X
             */
            int getAngleX() {return angleX;}

            /**
             * Set Plate Angle X
             *
             * @param newValue for Plate Angle X
             */
            void setAngleX(int newValue) {angleX = newValue;}

            /**
             * Get Plate Angle Y
             *
             * @return Plate Angle Y
             */
            int getAngleY() {return angleY;}

            /**
             * Set Plate Angle Y
             *
             * @param newValue for Plate Angle Y
             */
            void setAngleY(int newValue) {angleY = newValue;}

            /**
             * Set Front Side Plate Pic
             */
            void setFrontSidePlatePic(){
                plateSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/gtu_logo_front.png") );
            }

            /**
             * Set Front Side Plate Pic
             */
            void setBackSidePlatePic(){
                plateSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/gtu_logo_back.png") );
            }

            /**
             * Set Front Side Plate Pic
             */
            void setRightSidePlatePic(){
                plateSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/gtu_logo_right.png") );
            }

            /**
             * Set Front Side Plate Pic
             */
            void setLeftSidePlatePic(){
                plateSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/gtu_logo_left.png") );
            }

        private:
            IrrlichtDevice* device;        /** For IrrlichtDevice Pointer */
            ISceneNode* plateSceneNode;    /** For The Plate */
            int angleX;                    /** Angle X of Plate */
            int angleY;                    /** Angle Y of Plate */
    };
}

#endif // PLATE_H

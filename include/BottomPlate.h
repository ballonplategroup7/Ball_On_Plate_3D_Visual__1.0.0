/**
 * BottomPlate
 *
 * File:   BottomPlate.h
 *
 * Description:
 *
 *  Class for BottomPlate.
 *  BottomPlate have:
 *      - ISceneNode Object
 *      - Angle X
 *      - Angle Y
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifndef BOTTOMPLATE_H
#define BOTTOMPLATE_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace BallOnPlate
{
    class BottomPlate
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
            BottomPlate(IrrlichtDevice* newDevice,ISceneNode* parentNode);

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
             * Create BottomPlate
             */
            void createBottomPlate(ISceneNode* parentNode);

            /**
             * Get BottomPlate
             */
            ISceneNode* getBottomPlate(){return bottomPlateSceneNode;}

            /**
             * Get BottomPlate Angle X
             *
             * @return BottomPlate Angle X
             */
            int getAngleX() {return angleX;}

            /**
             * Set BottomPlate Angle X
             *
             * @param newValue for BottomPlate Angle X
             */
            void setAngleX(int newValue) {angleX = newValue;}

            /**
             * Get BottomPlate Angle Y
             *
             * @return BottomPlate Angle Y
             */
            int getAngleY() {return angleY;}

            /**
             * Set BottomPlate Angle Y
             *
             * @param newValue for BottomPlate Angle Y
             */
            void setAngleY(int newValue) {angleY = newValue;}

            /**
             * Set Front Side BottomPlate Pic
             */
            void setFrontBottomPlatePic(){
                bottomPlateSceneNode->setPosition(vector3df(0, -600, 0));
                bottomPlateSceneNode->setRotation (vector3df(0, 0, 0));
                bottomPlateSceneNode->setScale(vector3df(30.0f, 0.01f, 60.0f));
            }

            /**
             * Set Front Side BottomPlate Pic
             */
            void setBackPlatePic(){
                bottomPlateSceneNode->setPosition(vector3df(0, -600, 0));
                bottomPlateSceneNode->setRotation (vector3df(0, 0, 0));
                bottomPlateSceneNode->setScale(vector3df(30.0f, 0.01f, 60.0f));
            }

            /**
             * Set Front Side BottomPlate Pic
             */
            void setRightBottomPlatePic(){
                bottomPlateSceneNode->setPosition(vector3df(3, -959, -266));
                bottomPlateSceneNode->setRotation (vector3df(0, 0, 0));
                bottomPlateSceneNode->setScale(vector3df(81, 1, 50));
            }

            /**
             * Set Front Side BottomPlate Pic
             */
            void setLeftSideBottomPlatePic(){

            }

        private:
            IrrlichtDevice* device;        /** For IrrlichtDevice Pointer */
            ISceneNode* bottomPlateSceneNode;    /** For The BottomPlate */
            int angleX;                    /** Angle X of BottomPlate */
            int angleY;                    /** Angle Y of BottomPlate */
    };
}


#endif // BOTTOMPLATE_H

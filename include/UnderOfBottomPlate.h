/**
 * UnderOfBottomPlate
 *
 * File:   UnderOfBottomPlate.h
 *
 * Description:
 *
 *  Class for UnderOfBottomPlate.
 *  UnderOfBottomPlate have:
 *      - ISceneNode Object
 *      - Angle X
 *      - Angle Y
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifndef UNDEROFBOTTOMPLATE_H
#define UNDEROFBOTTOMPLATE_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace BallOnPlate
{
    class UnderOfBottomPlate
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
            UnderOfBottomPlate(int object,IrrlichtDevice* newDevice,ISceneNode* parentNode,
                                           double p1, double p2, double p3,
                                           double r1, double r2, double r3,
                                           double s1, double s2, double s3, ITexture* fileName);

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
             * Create UnderOfBottomPlate
             */
            void createUnderOfBottomPlate(ISceneNode* parentNode,double p1,double p2,double p3,
                                                                            double r1,double r2,double r3,
                                                                            double s1,double s2,double s3,ITexture* fileName);

            /**
             * Get UnderOfBottomPlate
             */
            ISceneNode* getUnderOfBottomPlate(){return underOfBottomPlateSceneNode;}

            /**
             * Set Front Side UnderOfBottomPlate Pic
             */
            void setFrontUnderOfBottomPlate(){

                underOfBottomPlateSceneNode->setPosition(vector3df(0,-750,0));
                underOfBottomPlateSceneNode->setRotation (vector3df(0, 0, 0 ));
                underOfBottomPlateSceneNode->setScale(vector3df(27.0f, 8.0f, 67.2f));

            }

            /**
             * Set Front Side UnderOfBottomPlate Pic
             */
            void setBackUnderOfBottomPlate(){
                underOfBottomPlateSceneNode->setPosition(vector3df(0,-750,0));
                underOfBottomPlateSceneNode->setRotation (vector3df(0, 0, 0 ));
                underOfBottomPlateSceneNode->setScale(vector3df(27.0f, 8.0f, 67.2f));
            }

            /**
             * Set Front Side UnderOfBottomPlate Pic
             */
            void setRightUnderOfBottomPlate(){
                underOfBottomPlateSceneNode->setPosition(vector3df(6,-1217,-213));
                underOfBottomPlateSceneNode->setRotation (vector3df(-9, 0, 0 ));
                underOfBottomPlateSceneNode->setScale(vector3df(94, 5, 33));
            }

            /**
             * Set Front Side UnderOfBottomPlate Pic
             */
            void setLeftUnderOfBottomPlate(){

            }

        private:
            IrrlichtDevice* device;                     /** For IrrlichtDevice Pointer */
            ISceneNode* underOfBottomPlateSceneNode;    /** For The UnderOfBottomPlate */
            int angleX;                                 /** Angle X of UnderOfBottomPlate */
            int angleY;                                 /** Angle Y of UnderOfBottomPlate */
    };
}


#endif // BOTTOMPLATE_H





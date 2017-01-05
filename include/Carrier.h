/**
 * Carrier
 *
 * File:   Carrier.h
 *
 * Description:
 *
 *  Class for Carrier.
 *  Carrier have:
 *      - ISceneNode Object
 *        TODO
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifndef CARRIER_H
#define CARRIER_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace BallOnPlate
{
    class Carrier
    {
        public:

            /**
             * One Parameter Constructor
             *
             * Call:
             *  - setDevice
             *  - createCarrier
             *  @param newDevice
             */
            Carrier(IrrlichtDevice* newDevice);

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
             * Create Carrier
             */
            void createCarrier();

            /**
            * Update Carrier Rotate
            */
            void update();

            /**
             * Get Carrier
             */
            ISceneNode* getCarrier(){return carrierSceneNode;}


        private:
            IrrlichtDevice* device;        /** For IrrlichtDevice Pointer */
            ISceneNode* carrierSceneNode;    /** For The Carrier */
    };
}




#endif // CARRIER_H

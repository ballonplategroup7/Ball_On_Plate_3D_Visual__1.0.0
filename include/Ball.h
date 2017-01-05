/**
 * Ball
 *
 * File:   Ball.h
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

#ifndef BALL_H
#define BALL_H

#include <irrlicht.h>
#include "Plate.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace BallOnPlate
{
    class Ball
    {
        public:

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
            Ball(IrrlichtDevice* newDevice,ISceneNode* parentNode);

            /**
            * Update Ball Position
            *
            * @param plate
            */
            void update(Plate *plate);

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
             * Create Ball
             */
            void createBall(ISceneNode* parentNode);

            /**
             * Get Ball
             */
            ISceneNode* getBall(){return ballSceneNode;}

            /**
             * Get Ball Position X Current
             *
             * @return Ball Position X Current
             */
            int getCurrentX() {
                return currentX;
            }

            /**
             * Set Ball Position X Current
             *
             * @param newValue for Ball Position X Current
             */
            void setCurrentX(int newValue) {
                setPreviousX(currentX);
                currentX = newValue;
            }

            /**
             * Get Ball Position Y Current
             *
             * @return Ball Position Y Current
             */
            int getCurrentY() {
                return currentY;
            }

            /**
             * Set Ball Position Y Current
             *
             * @param newValue for Ball Position Y Current
             */
            void setCurrentY(int newValue) {
                setPreviousY(currentY);
                currentY = newValue;
            }

            /**
             * Get Ball Position X Previous
             *
             * @return
             */
            int getPreviousX() {
                return previousX;
            }

            /**
             * Set Ball Position X Previous
             *
             * @param newValue for Ball Position X Previous
             */
            void setPreviousX(int newValue) {
                previousX = newValue;
            }

            /**
             * Get Ball Position Y Previous
             *
             * @return Ball Position Y Previous
             */
            int getPreviousY() {
                return previousY;
            }

            /**
             * Set Ball Position Y Previous
             *
             * @param newValue for Ball Position Y Previous
             */
            void setPreviousY(int newValue) {
                previousY = newValue;
            }

        private:
            IrrlichtDevice* device;    /** For IrrlichtDevice Pointer   */
            ISceneNode* ballSceneNode; /** For The Ball                 */
            int currentX;              /** Current Ball X Position      */
            int currentY;              /** Current Ball Y Position      */
            int previousX;             /** Previous Ball X Position     */
            int previousY;             /** Previous Ball Y Position     */
    };
}

#endif // BALL_H

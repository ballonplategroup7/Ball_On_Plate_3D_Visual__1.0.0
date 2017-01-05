/**
 * Ball On Plate
 *
 * File:   BallOnPlateEventReceiver.cpp
 *
 * Description:
 *
 *  Event Receiver of Ball On Plate
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifndef BALLONPLATEEVENTRECEIVER_H
#define BALLONPLATEEVENTRECEIVER_H

#include "BallOnPlate3DVisual.h"
 #include <iostream>
using namespace std;

/**
* Define some values that we'll use to identify individual GUI controls.
*/
enum
{
    GUI_ID_SHOW_CAMERAS_BUTTON = 101,
    GUI_ID_CAMERA_FRONT_SIDE_BUTTON,
    GUI_ID_CAMERA_BACK_SIDE_BUTTON,
    GUI_ID_CAMERA_RIGHT_SIDE_BUTTON,
    GUI_ID_CAMERA_LEFT_SIDE_BUTTON,
    GUI_ID_SHOW_MOVEMENTS_BUTTON,
    GUI_ID_INFINITY_MOVEMENT_BUTTON,
    GUI_ID_RECTANGLE_MOVEMENT_BUTTON,
    GUI_ID_CIRCLE_MOVEMENT_BUTTON,
    GUI_ID_CREATE_EQUILIBRIUM_POSITION_BUTTON,
    GUI_ID_MAP_OF_2D_PLATE,
    GUI_ID_MAP_OF_2D_PLATE_BORDER
};

namespace BallOnPlate
{
    class BallOnPlate3DVisual; //forward declaration

    class BallOnPlateEventReceiver : public IEventReceiver
    {
        public:

            /**
            * Default Constructor
            *
            * Call the setAllVariables function for system preparation
            */
            BallOnPlateEventReceiver();

            /**
            * One Parameter Constructor
            *
            * Call the setDevice and setAllVariables function for system preparation
            */
            virtual ~BallOnPlateEventReceiver();

            /**
            * If a button was clicked.
            */
            bool OnEvent(const SEvent& event);

            /**
            * Set Irrlicht Device
            */
            void setDevice();

            /**
            * Get Irrlicht Device
            */
            IrrlichtDevice* getDevice(){return device;}

            /**
            * Set Ball On Plate 3D Visual
            */
            void setBallOnPlate3DVisual();

            /**
            * Get Ball On Plate 3D Visual
            */
            BallOnPlate3DVisual* getBallOnPlate3DVisual(){return ballOnPlate3DVisual;}

        private:

            IrrlichtDevice* device;                     /* Irrlicht Device         */
            BallOnPlate3DVisual* ballOnPlate3DVisual;   /* Ball On Plate 3D Visual */
    };
}

#endif // BALLONPLATEEVENTRECEIVER_H

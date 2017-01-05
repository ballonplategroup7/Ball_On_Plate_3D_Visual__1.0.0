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

#include "BallOnPlateEventReceiver.h"


namespace
{
    /**
     * For Constant Variables
     *
     */
    const static int SCREEN_X=1024;
    const static int SCREEN_Y=720;

}


namespace BallOnPlate
{
    /**
    * Default Constructor
    *
    * Call the setAllVariables function for system preparation
    */
    BallOnPlateEventReceiver::BallOnPlateEventReceiver()
    {
        setDevice();
        setBallOnPlate3DVisual();
    }

    /**
    * One Parameter Constructor
    *
    * Call the setDevice and setAllVariables function for system preparation
    */
    BallOnPlateEventReceiver::~BallOnPlateEventReceiver()
    {
        delete ballOnPlate3DVisual;
    }

    /**
    * If a button was clicked.
    */
    bool BallOnPlateEventReceiver::OnEvent(const SEvent& event)
    {

        // Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			ballOnPlate3DVisual->setKeyisDown(event.KeyInput.Key, event.KeyInput.PressedDown);


        /**
         * If a button was clicked.
         */
        if (event.EventType == EET_GUI_EVENT)
        {
            s32 id = event.GUIEvent.Caller->getID();

            core::position2di Position;



            switch(event.GUIEvent.EventType)
            {

                /**
                * If a button was clicked.
                */
                case EGET_BUTTON_CLICKED:
                {

                    switch(id)
                    {

                    /**
                    * Set Visible to Camera buttons
                    */
                    case GUI_ID_SHOW_CAMERAS_BUTTON:{
                      //  PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->setVisibilityToCameraButtons();
                        return true;
                        }

                    /**
                    * Set Camera's Coordinates
                    * The front side of the plate
                    */
                    case GUI_ID_CAMERA_FRONT_SIDE_BUTTON:{
                      //  PlaySound(TEXT("Sounds/camera.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->setCameraCoordinatesToFront();
                        return true;
                        }

                    /**
                    * Set Camera's Coordinates
                    * The back side of the plate
                    */
                    case GUI_ID_CAMERA_BACK_SIDE_BUTTON:{
                      //  PlaySound(TEXT("Sounds/camera.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->setCameraCoordinatesToBack();
                        return true;
                    }


                    /**
                    * Set Camera's Coordinates
                    * The right side of the plate
                    */
                    case GUI_ID_CAMERA_RIGHT_SIDE_BUTTON:{
                      //  PlaySound(TEXT("Sounds/camera.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->setCameraCoordinatesToRight();
                        return true;
                    }


                    /**
                    * Set Camera's Coordinates
                    * The left side of the plate
                    */
                    case GUI_ID_CAMERA_LEFT_SIDE_BUTTON:{
                       // PlaySound(TEXT("Sounds/camera.wav"),NULL, SND_ASYNC);
                       // ballOnPlate3DVisual->setCameraCoordinatesToLeft();
                        return true;
                    }

                    /**
                    * Set Visible to movements buttons
                    */
                    case GUI_ID_SHOW_MOVEMENTS_BUTTON:{
                       // PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->setVisibilityToMovementsButtons();
                        return true;
                    }

                    /**
                    * Make infinity movement
                    */
                    case GUI_ID_INFINITY_MOVEMENT_BUTTON:{
                       // PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->makeInfinityMovement();
                        return true;
                    }

                    /**
                    * Make rectangle movement
                    */
                    case GUI_ID_RECTANGLE_MOVEMENT_BUTTON:{
                       // PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->makeRectangleMovement();
                        return true;
                    }

                    /**
                    * Make circle movement
                    */
                    case GUI_ID_CIRCLE_MOVEMENT_BUTTON:{
                       // PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                        ballOnPlate3DVisual->makeCircleMovement();
                        return true;
                    }

                    /**
                    * Create equilibrium position
                    */
                    case GUI_ID_CREATE_EQUILIBRIUM_POSITION_BUTTON:{
                       // PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                         ballOnPlate3DVisual->setVisibilityTo2DPlateMap();
                         return true;
                    }

                    /**
                    * Map of 2d Plate. Update Equilibrium
                    */
                    case GUI_ID_MAP_OF_2D_PLATE:{
                       // PlaySound(TEXT("Sounds/buttonSound.wav"),NULL, SND_ASYNC);
                         ballOnPlate3DVisual->updateEquilibriumPosition();
                         return true;
                    }

                    /**
                    * Default
                    */
                    default:
                        return false;
                    }
                    break;
                }

                default:
                    break;
            }
        }

        /**
         * If the mouse moves
         */
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
        {
           switch(event.MouseInput.Event)
           {
               case EMIE_MOUSE_MOVED:
                   // Update Mouse Position
                   ballOnPlate3DVisual->updateMousePosition(event.MouseInput.X, event.MouseInput.Y);
                   break;

               default:
                    break;
           }
        }


        return false;
    }


    /**
    * Set Irrlicht Device
    */
    void BallOnPlateEventReceiver::setDevice(){

        device = createDevice( video::EDT_SOFTWARE, core::dimension2d<u32>(SCREEN_X, SCREEN_Y));
        getDevice()->setWindowCaption(L"Gebze Technical University-Ball On Plate 3D");
    }

    /**
    * Set Ball On Plate 3D Visual
    */
    void BallOnPlateEventReceiver::setBallOnPlate3DVisual(){

        ballOnPlate3DVisual = new BallOnPlate3DVisual(getDevice());

    }



}

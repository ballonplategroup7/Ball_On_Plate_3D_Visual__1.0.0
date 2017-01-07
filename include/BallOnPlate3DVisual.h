/**
 * Ball On Plate
 *
 * File:   BallOnPlate3DVisual.h
 *
 * Description:
 *
 *  3D Visual of Ball On Plate
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifndef BALLONPLATE3DVISUAL_H
#define BALLONPLATE3DVISUAL_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "BallOnPlateEventReceiver.h"
#include "Plate.h"
#include "BottomPlate.h"
#include "UnderOfBottomPlate.h"
#include "Ball.h"
#include "Carrier.h"
#include "Equilibrium.h"
#include "Mouse.h"
#include "SerialCommunication.h"
#include "Plotting.h"
#include <ISceneCollisionManager.h>

#ifdef __linux__
  #include "SerialCommunicationLinux.h"
#elif defined _WIN32 || defined _WIN64
  #include "SerialCommunicationWindows.h"
  #include <MMSystem.h>
#else
#error "unknown platform"
#endif

namespace BallOnPlate
{
    class BallOnPlateEventReceiver; //  forward declaration

    class BallOnPlate3DVisual
    {
        public:

            /**
             * Default Constructor
             *
             * Call the setAllVariables function for system preparation
             */
            BallOnPlate3DVisual();

            /**
             * One Parameter Constructor
             *
             * Call the setDevice and setAllVariables function for system preparation
             * @param newDevice
             */
            BallOnPlate3DVisual(IrrlichtDevice* newDevice);

            /**
             * Virtual Constructors
             *
             * Delete:
             *   - Ball
             *   - Plate
             *   - Equilibrium
             *   - Mouse
             */
            virtual ~BallOnPlate3DVisual();

            /**
             * Run 3D
             */
            void run3D();

            /**
             * Set Visibility To Camera Buttons
             *
             * If camera button visible then make invisible
             * If camera button invisible then make visible
             */
            void setVisibilityToCameraButtons();

            /**
             * Set Camera Coordinates To Front
             */
            void setCameraCoordinatesToFront();

            /**
             * Set Camera Coordinates To Back
             */
            void setCameraCoordinatesToBack();

            /**
             * Set Camera Coordinates To Right
             */
            void setCameraCoordinatesToRight();

            /**
             * Set Camera Coordinates To Left
             */
            void setCameraCoordinatesToLeft();

            /**
             * Set Visibility To Movements Buttons
             *
             * If movements button visible then make invisible
             * If movements button invisible then make visible
             */
            void setVisibilityToMovementsButtons();

            /**
             * Set Visibility To 2D Plate Map
             *
             * If 2D Plate Map visible then make invisible
             * If 2D Plate Map invisible then make visible
             */
            void setVisibilityTo2DPlateMap();

            /**
             * Make Infinity Movement
             */
            void makeInfinityMovement();

            /**
             * Make Rectangle Movement
             */
            void makeRectangleMovement();

            /**
             * Make Circle Movement
             */
            void makeCircleMovement();

            /**
             * Update Equilibrium Position with use Mouse Position
             */
            void updateEquilibriumPosition();

            /**
             * Update Mouse Position
             *
             * @param newX
             * @param newY
             */
            void updateMousePosition(int newX, int newY);

            /**
             * Set KeyIsDown
             */
            void setKeyIsDown();

            /**
             * Set KeyIsDown index
             */
            void setKeyisDown(int index, bool value){KeyIsDown[index] = value;}

            /**
             * Get KeyIsDown
             */
            int getKeyisDown(int index){return KeyIsDown[index];}

        private:

            /**
             * Set all variables that the class needs:
             *   - Set Device
             *   - Add buttons
             *   - Set Ball
             *   - Set Plate
             *   - Set BottomPlate
             *   - Set UnderOfBottomPlate
             *   - Create Camera
             *   - Set Equilibrium
             *   - Set Mouse
             *   - Set Serial Communication
             */
            void setAllVariables();

            /**
             * Add Buttons :
             *   - Cameras
             *   - Cameras Front (invisible)
             *   - Cameras Back (invisible)
             *   - Cameras Right (invisible)
             *   - Cameras Left (invisible)
             *   - Movements
             *   - Infinity Movement (invisible)
             *   - Rectangle Movement (invisible)
             *   - Create Equilibrium Position
             *
             * Set Variables :
             *   - Set 0 for Plate Position X Equilibrium
             *   - Set 0 for Plate Position Y Equilibrium
             */
            void addButtons();

            /**
             * Get Show Cameras Button
             */
            IGUIButton* getShowCamerasButton(){return showCamerasButton;}

            /**
             * Get Camera Front Side Button
             */
            IGUIButton* getCameraFrontSideButton(){return cameraFrontSideButton;}

            /**
             * Get Camera Back Side Button
             */
            IGUIButton* getCameraBackSideButton(){return cameraBackSideButton;}

            /**
             * Get Camera Right Side Button
             */
            IGUIButton* getCameraRightSideButton(){return cameraRightSideButton;}

            /**
             * Get Camera Left Side Button
             */
            IGUIButton* getCameraLeftSideButton(){return cameraLeftSideButton;}

            /**
             * Get Show Movements Button
             */
            IGUIButton* getShowMovementsButton(){return showMovementsButton;}

            /**
             * Get Infinity Movement Button
             */
            IGUIButton* getInfinityMovementButton(){return infinityMovementButton;}

            /**
             * Get Rectangle Movement Button
             */
            IGUIButton* getRectangleMovementButton(){return rectangleMovementButton;}

            /**
             * Get Circle Movement Button
             */
            IGUIButton* getCircleMovementButton(){return circleMovementButton;}


            /**
             * Get Creat Equilibrium Position Button
             */
            IGUIButton* getCreateEquilibriumPosition(){return createEquilibriumPositionButton;}

            /**
             * Get Map Of 2D Plate
             */
            IGUIButton* getMapOf2DPlate(){return mapOf2DPlate;}

            /**
             * Get Map Of 2D Plate
             */
            IGUIButton* getMapOf2DPlateBorder(){return mapOf2DPlateBorder;}

            /**
             * Set Ball
             */
            void setBall(){ball = new Ball(getDevice(),getEmptyNode());}


            /**
             * Create Empty Node
             */
            void createEmptyNode();


            /**
             * Set Plate Carrier
             */
           void setCarrier(){carrier = new Carrier(getDevice());}

            /**
             * Get Empty Scene Node
             */
            ISceneNode* getEmptyNode(){return emptySceneNode;}


            /**
             * Get Ball
             */
            Ball* getBall(){return ball;}

            /**
             * Set Plate
             */
            void setPlate(){plate = new Plate(getDevice(),getEmptyNode(),
                           10.0f,0,0,0, 0, 0,0, 0, 0,24.0f, 0.01f, 30.0f, getVideoDriver()->getTexture("Textures/gtu_logo_front.png"));}

            /**
             * Get Plate
             */
            Plate* getPlate(){return plate;}



            /***************************************************************/



            void setMotorXPlace(){

                IMesh* mesh = getSceneManager()->getMesh("Textures/Design/MotorXPlace/MotorXPlace.3ds");
                motorXPlace = getSceneManager()->addMeshSceneNode(mesh);

                if (motorXPlace)
                 {
                    motorXPlace->setMaterialFlag( video::EMF_LIGHTING, true );
                    motorXPlace->setMaterialTexture(0, getDevice()->getVideoDriver()->getTexture("Textures/Design/MotorXPlace/MotorXPlace.jpg"));
                 }
            }


            void setFrontMotorXPlace(){

                if (motorXPlace)
                 {
                    /*motorXPlace->setPosition(vector3df(-224, -6, 294));
                    motorXPlace->setRotation (vector3df(-10, -2, -1));
                    motorXPlace->setScale(vector3df(97, 163, 104));*/

                    motorXPlace->setPosition(vector3df(-224, -6, 294));
                    motorXPlace->setRotation (vector3df(-10, -2, -1));
                    motorXPlace->setScale(vector3df(104, 167, 104));
                 }
            }

            void setBackMotorXPlace(){

                if (motorXPlace)
                 {
                    motorXPlace->setPosition(vector3df(189, -70, 308));
                    motorXPlace->setRotation (vector3df(-8, 1, -4));
                    motorXPlace->setScale(vector3df(107, 219, 105));

                 }
            }

            void setRightMotorXPlace(){

                if (motorXPlace)
                 {
                    motorXPlace->setPosition(vector3df(-16, -282, 375));
                    motorXPlace->setRotation (vector3df(-11, -2, 2));
                    motorXPlace->setScale(vector3df(241, 219, 130));

                 }
            }





            void setMotorX(){

                IMesh* mesh = getSceneManager()->getMesh("Textures/Design/MotorX/MotorX.3ds");
                motorX= getSceneManager()->addMeshSceneNode(mesh);

                if (motorX)
                 {
                    motorX->setMaterialFlag( video::EMF_LIGHTING, true );
                    motorX->setMaterialTexture(0, getDevice()->getVideoDriver()->getTexture("Textures/Design/MotorX/MotorX.jpg"));
                 }
            }


            void setFrontMotorX(){

                if (motorX)
                 {
                    motorX->setPosition(vector3df(97, -1, 114));
                    motorX->setRotation (vector3df(-10, 85, -4));
                    motorX->setScale(vector3df(186, 161, 158));
                 }
            }

            void setBackMotorX(){

                if (motorX)
                 {
                    motorX->setPosition(vector3df(-100, -51, 41));
                    motorX->setRotation (vector3df(10, 85, 4));
                    motorX->setScale(vector3df(-177, 203, -158));
                 }
            }

            void setRightMotorX(){

                if (motorX)
                 {
                    motorX->setPosition(vector3df(325, -24, 203));
                    motorX->setRotation (vector3df(-13, 86, 10));
                    motorX->setScale(vector3df(186, 161, 158));
                 }
            }









            void setMotorY(){

                IMesh* mesh = getSceneManager()->getMesh("Textures/Design/MotorY/MotorY.3ds");
                motorY= getSceneManager()->addMeshSceneNode(mesh);

                if (motorY)
                 {
                    motorY->setMaterialFlag( video::EMF_LIGHTING, true );
                    motorY->setMaterialTexture(0, getDevice()->getVideoDriver()->getTexture("Textures/Design/MotorY/MotorY.jpg"));
                 }
            }


            void setFrontMotorY(){

                if (motorY)
                 {
                    motorY->setPosition(vector3df(-1000, -1000, -1000));
                    motorY->setRotation (vector3df(100, 100, 100));
                    motorY->setScale(vector3df(100, 100, 100));
                 }
            }

            void setBackMotorY(){

                if (motorY)
                 {
                    motorY->setPosition(vector3df(-79, -51, -39));
                    motorY->setRotation (vector3df(10, 85, 4));
                    motorY->setScale(vector3df(-177, 203, -158));
                 }
            }

            void setRightMotorY(){

                if (motorY)
                 {
                    motorY->setPosition(vector3df(1000, 1000, 1000));
                    motorY->setRotation (vector3df(200, 200, 200));
                    motorY->setScale(vector3df(200,200 ,200 ));
                 }
            }







            void setMotorYPlace(){

                IMesh* mesh = getSceneManager()->getMesh("Textures/Design/MotorYPlace/MotorYPlace.3ds");
                motorYPlace = getSceneManager()->addMeshSceneNode(mesh);

                if (motorYPlace)
                 {
                    motorYPlace->setMaterialFlag( video::EMF_LIGHTING, true );
                    motorYPlace->setMaterialTexture(0, getDevice()->getVideoDriver()->getTexture("Textures/Design/MotorYPlace/MotorYPlace.jpg"));
                 }
            }


            void setFrontMotorYPlace(){

                if (motorYPlace)
                 {  // motorYPlace->setPosition(vector3df(-110, -342, 121));
                    motorYPlace->setPosition(vector3df(-104, -342, 34));
                    motorYPlace->setRotation (vector3df(-5, 88, -59));
                    motorYPlace->setScale(vector3df(307, 403, -154));
                 }
            }

            void setBackMotorYPlace(){

                if (motorYPlace)
                 {  // motorYPlace->setPosition(vector3df(-110, -342, 121));
                    motorYPlace->setPosition(vector3df(448, -306, -19));
                    motorYPlace->setRotation (vector3df(74, 88, 85));
                    motorYPlace->setScale(vector3df(-261, 262, 147));
                 }
            }

            void setRightMotorYPlace(){

                if (motorYPlace)
                 {  // motorYPlace->setPosition(vector3df(-110, -342, 121));
                    motorYPlace->setPosition(vector3df(465, -375, 3));
                    motorYPlace->setRotation (vector3df(74, 88, 85));
                    motorYPlace->setScale(vector3df(220, 292, 157));
                 }
            }







            void setMainCarrier(){

                IMesh* mesh = getSceneManager()->getMesh("Textures/Design/MainCarrier/MainCarrier.3ds");
                mainCarrier = getSceneManager()->addMeshSceneNode(mesh);

                if (mainCarrier)
                 {
                    mainCarrier->setMaterialFlag( video::EMF_LIGHTING, true );
                    mainCarrier->setMaterialTexture(0, getDevice()->getVideoDriver()->getTexture("Textures/Design/MainCarrier/MainCarrier.jpg"));
                 }
            }


            void setFrontMainCarrier(){

                if (mainCarrier)
                 {
                    mainCarrier->setPosition(vector3df(-216, -342, 268));
                    mainCarrier->setRotation (vector3df(-5, 88, -59));
                    mainCarrier->setScale(vector3df(1811, 403, -121));
                 }
            }


            void setBackMainCarrier(){

                if (mainCarrier)
                 {
                    mainCarrier->setPosition(vector3df(-491, -197, 442));
                    mainCarrier->setRotation (vector3df(93, 90, -28));
                    mainCarrier->setScale(vector3df(3033, 650, 2593));
                 }
            }

            void setRightMainCarrier(){

                if (mainCarrier)
                 {
                    mainCarrier->setPosition(vector3df(22, 16, 299));
                    mainCarrier->setRotation (vector3df(204, 89, 24));
                    mainCarrier->setScale(vector3df(3024, 1059, 2582));
                 }
            }



            void setMainCarrierBottom(){

                  mainCarrierBottom = getSceneManager()->addCubeSceneNode(10.0f,0,0,
                            vector3df(-101, -376, 2),//position
                            vector3df(-5, 17, -13),//rotation
                            vector3df(4, 0, 10)); //scale

                    mainCarrierBottom->setMaterialFlag(video::EMF_LIGHTING, false);

                    mainCarrierBottom->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/Design/MainCarrierBottom/MainCarrierBottom.jpg") );
            }


            void setFrontMainCarrierBottom(){

                if (mainCarrierBottom)
                 {
                    mainCarrierBottom->setPosition(vector3df(-101, -376, 2));
                    mainCarrierBottom->setRotation (vector3df(-5, 17, -13));
                    mainCarrierBottom->setScale(vector3df(4, 0, 10));
                 }
            }

            void setBackMainCarrierBottom(){

                if (mainCarrierBottom)
                 {
                    mainCarrierBottom->setPosition(vector3df(14, -696, -6));
                    mainCarrierBottom->setRotation (vector3df(-5,17, -13));
                    mainCarrierBottom->setScale(vector3df(5, 0, 14));
                 }
            }

            void setRightMainCarrierBottom(){

                if (mainCarrierBottom)
                 {
                    mainCarrierBottom->setPosition(vector3df(1000, 1000, 1000));
                    mainCarrierBottom->setRotation (vector3df(200,200, 200));
                    mainCarrierBottom->setScale(vector3df(200, 200, 200));
                 }
            }




            void setServoMotorXStick(){

                 servoMotorXStick = getSceneManager()->addCubeSceneNode(10.0f,0,0);
                servoMotorXStick->setMaterialFlag(video::EMF_LIGHTING, true);
                servoMotorXStick->setMaterialTexture( 0, getDevice()->getVideoDriver()->getTexture("Textures/Design/ServoMotorXStick/ServoMotorXStick.png") );



                servoMotorXStick->setPosition(vector3df(340, -875, 340));
                servoMotorXStick->setRotation (vector3df(-10.0, 0.0, -2.0));
                servoMotorXStick->setScale(vector3df(1.0f, 103.0f, 1.0f));

                servoMotorXStickXPosition = 340;
                servoMotorXStickYPosition = -875;

            }

            void setFrontServoMotorXStick(){

                if (servoMotorXStick)
                 {

                    servoMotorXStickXPosition = 340;
                    servoMotorXStickYPosition = -875;

                    servoMotorXStick->setPosition(vector3df(340 + getPlate()->getAngleX()/3,
                                                            -875 + getPlate()->getAngleX()/3,
                                                            340));
                    servoMotorXStick->setRotation (vector3df(-10.0, 0.0, -2.0));
                    servoMotorXStick->setScale(vector3df(1.0f, 103.0f, 1.0f));
                 }
            }

            void setBackServoMotorXStick(){

                if (servoMotorXStick)
                 {

                    servoMotorXStickXPosition = -176;
                    servoMotorXStickYPosition = -727;

                    servoMotorXStick->setPosition(vector3df(-176 + getPlate()->getAngleX()/3,
                                                            -727 + getPlate()->getAngleX()/3,
                                                            309));
                    servoMotorXStick->setRotation (vector3df(-6, 0, 2));
                    servoMotorXStick->setScale(vector3df(-1.0f, 54.0f, -0.6f));

                 }
            }

            void setRightServoMotorXStick(){

                if (servoMotorXStick)
                 {

                    servoMotorXStickXPosition = 26;
                    servoMotorXStickYPosition = -168;

                    servoMotorXStick->setPosition(vector3df(26  + getPlate()->getAngleX()/3,
                                                            -168 + getPlate()->getAngleX()/3,
                                                             2));
                    servoMotorXStick->setRotation (vector3df(-258, 0, -32));
                    servoMotorXStick->setScale(vector3df(0.5f, 22, 0.5f));

                 }
            }


            void setServoMotorYStick(){

                 servoMotorYStick = getSceneManager()->addCubeSceneNode(10.0f,0,0);
                servoMotorYStick->setMaterialFlag(video::EMF_LIGHTING, true);
                servoMotorYStick->setMaterialTexture( 0, getDevice()->getVideoDriver()->getTexture("Textures/Design/ServoMotorXStick/ServoMotorXStick.png") );

                servoMotorYStick->setPosition(vector3df(71, -155, 21));
                servoMotorYStick->setRotation (vector3df(1, 0, -52));
                servoMotorYStick->setScale(vector3df(0.5f, 22.0f, 0.5f));

                servoMotorYStickXPosition = 71;
                    servoMotorYStickYPosition = -155;

            }

            void setFrontServoMotorYStick(){

                 servoMotorYStick->setVisible(1);

                if (servoMotorYStick)
                 {
                     servoMotorYStickXPosition = 71;
                    servoMotorYStickYPosition = -155;

                    servoMotorYStick->setPosition(vector3df(71  + getPlate()->getAngleY()/3,
                                                            -155 + getPlate()->getAngleY()/3,
                                                             21));
                    servoMotorYStick->setRotation (vector3df(1, 0, -52));
                    servoMotorYStick->setScale(vector3df(0.5f, 22.0f, 0.5f));
                 }
            }


            void setBackServoMotorYStick(){

                 servoMotorYStick->setVisible(1);

                if (servoMotorYStick)
                 {

                    servoMotorYStickXPosition = -71;
                    servoMotorYStickYPosition = -155;

                    servoMotorYStick->setPosition(vector3df(-71  + getPlate()->getAngleY()/3,
                                                            -155 + getPlate()->getAngleY()/3,
                                                             19));
                    servoMotorYStick->setRotation (vector3df(-6, -2, 173));
                    servoMotorYStick->setScale(vector3df(39.5f, 1, -0.5f));

                 }
            }


            void setRightServoMotorYStick(){

                 servoMotorYStick->setVisible(0);

                if (servoMotorXStick)
                 {

                    servoMotorXStickXPosition = 26;
                    servoMotorXStickYPosition = -168;

                    servoMotorXStick->setPosition(vector3df(26  + getPlate()->getAngleX()/3,
                                                            -168 + getPlate()->getAngleX()/3,
                                                             2));
                    servoMotorXStick->setRotation (vector3df(-258, 0, -32));
                    servoMotorXStick->setScale(vector3df(0.5f, 22, 0.5f));

                 }
            }


            /**
             * Set BottomPlate
             */
            void setBottomPlate(){bottomPlate = new BottomPlate(getDevice(),getEmptyNode());}

            /**
             * Get BottomPlate
             */
            BottomPlate* getBottomPlate(){return bottomPlate;}

            /**
             * Set UnderOfBottomPlate
             */
            void setUnderOfBottomPlate(){underOfBottomPlate = new UnderOfBottomPlate(0,getDevice(),getEmptyNode(),
                                                                                     0,-750,0,0, 0, 0, 27.0f, 8.0f, 67.2f, getVideoDriver()->getTexture("Textures/Design/UnderOfBottomPlate/underOfBottomPlate.png"));}

            /**
             * Get BottomPlate
             */
            UnderOfBottomPlate* getUnderOfBottomPlate(){return underOfBottomPlate;}



            /**
             * Create Camera
             */
            void createCamera();

            /**
             * Get Camera
             */
            ICameraSceneNode* getCamera(){return camera;}

            /**
             * Set Irrlicht Device
             */
            void setDevice();

            /**
             * Set Irrlicht Device
             */
            void setDevice(IrrlichtDevice* newDevice){device = newDevice;}

            /**
             * Get Irrlicht Device
             */
            IrrlichtDevice* getDevice(){return device;}

            /**
             * Get Video Driver
             */
            IVideoDriver* getVideoDriver(){return getDevice()->getVideoDriver();}

            /**
             * Get Scene Manager
             */
            ISceneManager* getSceneManager(){return getDevice()->getSceneManager();}

            /**
             * Get GUI Environment
             */
            IGUIEnvironment* getGUIEnvironment(){return getDevice()->getGUIEnvironment();}

            /**
             * Get ISceneCollisionManager
             */
            scene::ISceneCollisionManager* getISceneCollisionManager(){return getSceneManager()->getSceneCollisionManager();}

            /**
             * Set Equilibrium
             */
            void setEquilibrium() {equilibrium = new Equilibrium();}

            /**
             * Get Equilibrium
             *
             * @return Equilibrium
             */
            Equilibrium* getEquilibrium() {return equilibrium;}

            /**
             * Set Mouse
             */

            void setMouse() {mouse = new Mouse();}

            /**
             * Get Mouse
             *
             * @return Mouse
             */
            Mouse* getMouse() {return mouse;}

             /**
             * Set Operation
             */
            void setOperation(int newOperation) {operation = newOperation;}

            /**
             * Get Operation
             *
             * @return int
             */
            int getOperation() {return operation;}

            /**
             * Set Serial Communication For Windows or For Linux
             *
             * @return SerialCommunication
             */
            void setSerialCommunication();

            /**
             * Get Serial Communication
             *
             * @return SerialCommunication
             */
            SerialCommunication* getSerialCommunication() {return serialCommunication;}

            /**
             * Check Keyboard For Plate
             */
            void checkKeyboardForPlate();

            /**
             * Check Keyboard For Ball
             */
            void checkKeyboardForBall();

             /**
             * //Do not change this value  u8=255 char max
             * rectX(0*,0, 255*, 100) 0-255 and 0-100
             * rectY(0*,0, 255*, 100) 0-255 and 0-100
             */
            void setPlotXYLeft() {
                plotX = new Plotting(L"Xcoor", device, rect<s32>(795, 400, 1020, 500));
                plotY = new Plotting(L"Ycoor", device, rect<s32>(795, 510, 1020, 610));
            }
            /**
             * //Do not change this value  u8=255 char max
             * rectX(0*,0, 255*, 100) 0-255 and 0-100
             * rectY(0*,0, 255*, 100) 0-255 and 0-100
             */
            void setPlotXYRight() {
                plotX = new Plotting(L"Xcoor", device, rect<s32>(5, 400, 260, 500));
                plotY = new Plotting(L"Ycoor", device, rect<s32>(5, 510, 260, 610));
            }

            int mapTo(int  x, int in_min, int in_max, int out_min, int out_max)
            {
                return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
            }


            /* Data Field */
            IrrlichtDevice* device;                        /** Irrlicht Device                    */

            /* Buttons */
            IGUIButton* showCamerasButton;                 /** CAMERAS_BUTTON                     */
            IGUIButton* cameraFrontSideButton;             /** CAMERA_FRONT_SIDE_BUTTON           */
            IGUIButton* cameraBackSideButton;              /** CAMERA_BACK_SIDE_BUTTON            */
            IGUIButton* cameraRightSideButton;             /** CAMERA_RIGHT_SIDE_BUTTON           */
            IGUIButton* cameraLeftSideButton;              /** CAMERA_LEFT_SIDE_BUTTON            */
            IGUIButton* showMovementsButton;               /** MOVEMENTS_BUTTONS                  */
            IGUIButton* infinityMovementButton;            /** INFINITY_MOVEMENT_BUTTON           */
            IGUIButton* rectangleMovementButton;           /** RECTANGLE_MOVEMENT_BUTTON          */
            IGUIButton* circleMovementButton;              /** CIRCLE_MOVEMENT_BUTTON             */
            IGUIButton* createEquilibriumPositionButton;   /** CREATE_EQUILIBRIUM_POSITION_BUTTON */
            IGUIButton* mapOf2DPlate;                      /** Map Of 2D Plate                    */
            IGUIButton* mapOf2DPlateBorder;

            Ball* ball;                                    /** For The Ball                       */
            Plate* plate;                                  /** For The Plate                      */

            Plate* servoMotorXPropeller;                   /** For The servoMotorXPropeller       */
            BottomPlate* bottomPlate;                      /** For The BottomPlate                */
            UnderOfBottomPlate* underOfBottomPlate;        /** For The underOfBottomPlate         */
            Carrier* carrier;                              /** For The Plate Carrier              */
            ICameraSceneNode* camera;                      /** For The Camera                     */

            Equilibrium* equilibrium;                      /** Equilibrium Of Plate               */
            Mouse* mouse;                                  /** Mouse                              */
            int operation;                                 /** Operation                          */

            SerialCommunication *serialCommunication;      /** Serial Communication               */

            bool KeyIsDown[KEY_KEY_CODES_COUNT];           /** We use this array to store the current state of each key */



            IMeshSceneNode* motorX;
            IMeshSceneNode* motorXPlace;

            IMeshSceneNode* motorY;
            IMeshSceneNode* motorYPlace;


            IMeshSceneNode* mainCarrier;
            ISceneNode* mainCarrierBottom;


            ISceneNode* servoMotorXStick;                       /** For The servoMotorXStick           */
            ISceneNode* servoMotorYStick;                       /** For The servoMotorYStick           */

            Plotting* plotX;
            Plotting* plotY;

            ISceneNode* emptySceneNode;

            int servoMotorXStickXPosition;
            int servoMotorXStickYPosition;
            int servoMotorYStickXPosition;
            int servoMotorYStickYPosition;
    };
}

#endif // BALLONPLATE3DVISUAL_H

/**
 * Ball On Plate
 *
 * File:   BallOnPlate3DVisual.cpp
 *
 * Description:
 *
 *  3D Visual of Ball On Plate
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */
 #include <iostream>
using namespace std;
#include "BallOnPlate3DVisual.h"

namespace
{
    /**
     * For Constant Variables
     *
     */
    const static int SCREEN_X=1024;                /**  Size Of Screen X                                  */
    const static int SCREEN_Y=720;                 /**  Size Of Screen Y                                  */
    const static int OUT_OF_SYSTEM=-1453;          /**  Constant variable which have value out of system. */

    const static int PLATE_MAX_X= 100;             /**  Maximum Value for Plate X                         */
    const static int PLATE_MIN_X= -100;            /**  Minimum Value for Plate X                         */
    const static int PLATE_MAX_Y= 85;              /**  Maximum Value for Plate Y                         */
    const static int PLATE_MIN_Y= -85;             /**  Minimum Value for Plate Y                         */

    const static int OPERATION_EQUILIBRIUM = 101;  /**  Value of operation equilibrium                    */
    const static int OPERATION_INFINITY = 102;     /**  Value of operation infinity                       */
    const static int OPERATION_RECTANGLE = 103;    /**  Value of operation rectangle                      */
    const static int OPERATION_CIRCLE = 104;       /**  Value of operation circle                         */

    const static bool IS_KEYBOARD_ACTIVE = true;   /** is keyboard active                                 */
}

namespace BallOnPlate
{
    /**
    * Default Constructors
    *
    * Call the setAllVariables function for system preparation
    */
    BallOnPlate3DVisual::BallOnPlate3DVisual()
    {
        setDevice();
        setAllVariables();
        setKeyIsDown();
    }

    /**
    * One Parameter Constructor
    *
    * Call the setDevice and setAllVariables function for system preparation
    */
    BallOnPlate3DVisual::BallOnPlate3DVisual(IrrlichtDevice* newDevice)
    {
        setDevice(newDevice);
        setAllVariables();
        setKeyIsDown();
    }

    /**
    * Virtual Constructors
    *
    * Delete:
    *   - Ball
    *   - Plate
    *   - Equilibrium
    *   - Mouse
    */
    BallOnPlate3DVisual::~BallOnPlate3DVisual()
    {
        delete plotX;
        delete plotY;
        delete getBall();
        delete getPlate();
        delete getEquilibrium();
        delete getMouse();
    }

    /**
    * Run 3D
    */
    void BallOnPlate3DVisual::run3D()
    {
        /** Show The Device Screen */
        getDevice()->setResizable(true);

        /** Run Loop */
        while(getDevice()->run() && getVideoDriver())
        if (getDevice()->isWindowActive())
        {
            /** Check Keyboard For Plate */
            checkKeyboardForPlate();

            /** Check Keyboard For Ball */
            checkKeyboardForBall();

            /** Send Outputs to Arduino */
            getSerialCommunication()->sendOutputsToArduino(getOperation(),*getEquilibrium());

            /** Begin Draw */
            //getVideoDriver()->beginScene(true, true, SColor(255,0,20,150));
            //getVideoDriver()->beginScene(true, true, SColor(255,255,250,221));
            getVideoDriver()->beginScene(true, true, SColor(255,26,53,80));

            /** Draw GUI Environment */
            getGUIEnvironment()->drawAll();

            /** Draw Scene Manager */
            getSceneManager()->drawAll();

             plotX->drawRed();
            plotY->drawYellow();
            //TODO degerleri mapleme

             plotX->addValue((irr::u8)mapTo(ball->getCurrentX(),-100,100,0,100));
            plotY->addValue((irr::u8)mapTo(ball->getCurrentY(),-80,80,10,90));

           /* plotX->addValue((irr::u8)rand()%plotX->getMax());
            plotY->addValue((irr::u8)rand()%plotX->getMax());*/
            //ball->getCurrentY()% plotY->getMax()

            /** End Draw */
            getVideoDriver()->endScene();

            /** Take Inputs from Arduino */
            getSerialCommunication()->takeInputsFromArduino(getBall(),getPlate());

            /** Plate Update */
            getPlate()->update( servoMotorXStick, servoMotorYStick,
                               servoMotorXStickXPosition,servoMotorXStickYPosition,
                               servoMotorYStickXPosition,servoMotorYStickYPosition);

            /** Ball Update */
            getBall()->update(getPlate());
        }

        /** Send Outputs to Arduino */
        getSerialCommunication()->sendOutputsToArduinoConnectEnd();


        /** End of the program */
        getDevice()->drop();
    }

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
    void BallOnPlate3DVisual::setAllVariables()
    {
        addButtons();
        createEmptyNode();
        setBall();
        setPlate();
        setBottomPlate();
        setUnderOfBottomPlate();


        setMotorXPlace();
        setFrontMotorXPlace();

        setMotorX();
        setFrontMotorX();

        setMotorY();
        setFrontMotorY();

        setMotorYPlace();
        setFrontMotorYPlace();

        setMainCarrier();
        setFrontMainCarrier();

        setMainCarrierBottom();
        setFrontMainCarrierBottom();

        setServoMotorXStick();
        setFrontServoMotorXStick();

        setServoMotorYStick();
        setFrontServoMotorYStick();



        setPlotXYRight();



        createCamera();
        setEquilibrium();
        setMouse();
        setOperation(OPERATION_EQUILIBRIUM);
        setSerialCommunication();
    }

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
    void BallOnPlate3DVisual::addButtons()
    {
        int x = SCREEN_X / 85;
        int y = SCREEN_Y / 36;
        int width = SCREEN_Y / 4 ;
        int height = SCREEN_X / 18;

        /* CAMERAS_BUTTON               */
        showCamerasButton = getGUIEnvironment()->addButton(rect<s32>(x,y,x+width,y + height), 0, GUI_ID_SHOW_CAMERAS_BUTTON,
			L"", L"Show Cameras");
			showCamerasButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/camerasButton.png"));

        /* CAMERA_FRONT_SIDE_BUTTON     */
        cameraFrontSideButton = getGUIEnvironment()->addButton(rect<s32>(x+width,y,x+2*width,y+ height), 0, GUI_ID_CAMERA_FRONT_SIDE_BUTTON,
			L"", L"Show Front");
        cameraFrontSideButton->setVisible(0);
            cameraFrontSideButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/frontCameraButton.png"));

        /* CAMERA_BACK_SIDE_BUTTON      */
        cameraBackSideButton = getGUIEnvironment()->addButton(rect<s32>(x+2*width,y,x+3*width,y + height), 0, GUI_ID_CAMERA_BACK_SIDE_BUTTON,
			L"", L"Show Back");
        cameraBackSideButton->setVisible(0);
            cameraBackSideButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/backCameraButton.png"));

        /* CAMERA_RIGHT_SIDE_BUTTON     */
        cameraRightSideButton = getGUIEnvironment()->addButton(rect<s32>(x+3*width,y,x+4*width,y + height), 0, GUI_ID_CAMERA_RIGHT_SIDE_BUTTON,
			L"", L"Show Right");
         cameraRightSideButton->setVisible(0);
         cameraRightSideButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/rightCameraButton.png"));

        /* CAMERA_LEFT_SIDE_BUTTON      */
        cameraLeftSideButton = getGUIEnvironment()->addButton(rect<s32>(x+4*width,y,x+5*width,y + height), 0, GUI_ID_CAMERA_LEFT_SIDE_BUTTON,
			L"", L"Show Left");
         cameraLeftSideButton->setVisible(0);
         cameraLeftSideButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/leftCameraButton.png"));

        /* MOVEMENTS_BUTTONS            */
         showMovementsButton = getGUIEnvironment()->addButton(rect<s32>(x,y+height,x+width,y+height + height), 0, GUI_ID_SHOW_MOVEMENTS_BUTTON,
			L"", L"Show Movements");
			showMovementsButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/movementsButton.png"));

        /* INFINITY_MOVEMENT_BUTTON     */
         infinityMovementButton = getGUIEnvironment()->addButton(rect<s32>(x+width,y+height,x+2*width,y+height + height), 0, GUI_ID_INFINITY_MOVEMENT_BUTTON,
			L"", L"Draw Infinity");
         infinityMovementButton->setVisible(0);
           infinityMovementButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/infinityButton.png"));

        /* RECTANGLE_MOVEMENT_BUTTON    */
         rectangleMovementButton = getGUIEnvironment()->addButton(rect<s32>(x+2*width,y+height,x+3*width,y+height + height), 0, GUI_ID_RECTANGLE_MOVEMENT_BUTTON,
			L"", L"Draw Rectangle");
         rectangleMovementButton->setVisible(0);
         rectangleMovementButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/rectangleButton.png"));

        /* CIRCLE_MOVEMENT_BUTTON    */
         circleMovementButton = getGUIEnvironment()->addButton(rect<s32>(x+3*width,y+height,x+4*width,y+height + height), 0, GUI_ID_CIRCLE_MOVEMENT_BUTTON,
			L"", L"Draw Circle");
         circleMovementButton->setVisible(0);
         circleMovementButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/circleButton.png"));

        /* CREATE_EQUILIBRIUM_POSITION_BUTTON */
         createEquilibriumPositionButton = getGUIEnvironment()->addButton(rect<s32>(x,y+2*height,x+width,y+2*height + height), 0, GUI_ID_CREATE_EQUILIBRIUM_POSITION_BUTTON,
 			L"", L"Create Equilibrium Position");
 			createEquilibriumPositionButton->setImage(getVideoDriver()->getTexture("Textures/Buttons/changeEqPositionButton.png"));


         /* Map Of 2D Plate */
         mapOf2DPlateBorder = getGUIEnvironment()->addButton(rect<s32>(x+10,y+3*height+7,(x+10) + PLATE_MAX_X*2+10,(y+3*height+7)  + PLATE_MAX_Y*2 +10), 0, GUI_ID_MAP_OF_2D_PLATE_BORDER);
         mapOf2DPlateBorder->setVisible(0);
         mapOf2DPlateBorder->setImage(getVideoDriver()->getTexture("Textures/gtu_logo2_kenarlar.png"));

         /* Map Of 2D Plate */
         mapOf2DPlate = getGUIEnvironment()->addButton(rect<s32>(x+20,y+3*height+17,(x+10) + PLATE_MAX_X*2,(y+3*height+7)  + PLATE_MAX_Y*2), 0, GUI_ID_MAP_OF_2D_PLATE);
         mapOf2DPlate->setVisible(0);
         mapOf2DPlate->setImage(getVideoDriver()->getTexture("Textures/Design/GtuLogo/gtu_logo2.png"));

    }

    /**
    * Set Visibility To Camera Buttons
    *
    * If camera button visible then make invisible
    * If camera button invisible then make visible
    */
    void BallOnPlate3DVisual::setVisibilityToCameraButtons()
    {
        if(getCameraFrontSideButton()->isVisible() == true){
            getCameraFrontSideButton()->setVisible(0);
            getCameraBackSideButton()->setVisible(0);
            getCameraRightSideButton()->setVisible(0);
            getCameraLeftSideButton()->setVisible(0);
        }

        else{
            getCameraFrontSideButton()->setVisible(1);
            getCameraBackSideButton()->setVisible(1);
            getCameraRightSideButton()->setVisible(1);
            getCameraLeftSideButton()->setVisible(1);
        }

    }

    /**
    * Set Camera Coordinates To Front
    */
    void BallOnPlate3DVisual::setCameraCoordinatesToFront()
    {
        camera = getSceneManager()->addCameraSceneNode(0, vector3df(-320,320,0), vector3df(1,1,0),false);
        plate->setFrontSidePlatePic();

        bottomPlate->setFrontBottomPlatePic();
        underOfBottomPlate->setFrontUnderOfBottomPlate();
        setFrontMotorXPlace();
        setFrontMotorX();
        setFrontMotorY();
        setFrontMotorYPlace();
        setFrontMainCarrier();
        setFrontMainCarrierBottom();
        setFrontServoMotorXStick();
        setFrontServoMotorYStick();
    }

    /**
    * Set Camera Coordinates To Back
    */
    void BallOnPlate3DVisual::setCameraCoordinatesToBack(){
         camera = getSceneManager()->addCameraSceneNode(0, vector3df(320,320,0), vector3df(1,1,0),false);
         plate->setBackSidePlatePic();

         bottomPlate->setBackPlatePic();
         underOfBottomPlate->setBackUnderOfBottomPlate();
         setBackMotorXPlace();
         setBackMotorX();
         setBackMotorY();
         setBackMotorYPlace();
         setBackMainCarrier();
         setBackMainCarrierBottom();
         setBackServoMotorXStick();
         setBackServoMotorYStick();
    }

    /**
    * Set Camera Coordinates To Right
    */
    void BallOnPlate3DVisual::setCameraCoordinatesToRight(){
         camera = getSceneManager()->addCameraSceneNode(0, vector3df(0,320,320), vector3df(1,1,0),false);
         plate->setRightSidePlatePic();

         bottomPlate->setRightBottomPlatePic();
         underOfBottomPlate->setRightUnderOfBottomPlate();

         setRightMotorXPlace();
         setRightMotorX();
         setRightMotorY();
         setRightMotorYPlace();
         setRightMainCarrier();
         setRightMainCarrierBottom();
         setRightServoMotorXStick();
         setRightServoMotorYStick();
    }

    /**
    * Set Camera Coordinates To Left
    */
    void BallOnPlate3DVisual::setCameraCoordinatesToLeft(){
        camera = getSceneManager()->addCameraSceneNode(0, vector3df(0,320,-320), vector3df(1,1,0),false);
        plate->setLeftSidePlatePic();
        /** Fps
         camera = getSceneManager()->addCameraSceneNodeFPS();*/

    }

    /**
    * Set Visibility To Movements Buttons
    *
    * If movements button visible then make invisible
    * If movements button invisible then make visible
    */
    void BallOnPlate3DVisual::setVisibilityToMovementsButtons()
    {
        if(getInfinityMovementButton()->isVisible() == true){
            getInfinityMovementButton()->setVisible(0);
            getRectangleMovementButton()->setVisible(0);
            getCircleMovementButton()->setVisible(0);
        }

        else{
            getInfinityMovementButton()->setVisible(1);
            getRectangleMovementButton()->setVisible(1);
            getCircleMovementButton()->setVisible(1);
        }
    }

    /**
     * Set Visibility To 2D Plate Map
     *
     * If 2D Plate Map visible then make invisible
     * If 2D Plate Map invisible then make visible
     */
    void BallOnPlate3DVisual::setVisibilityTo2DPlateMap()
    {
        if(getMapOf2DPlate()->isVisible() == true){
            getMapOf2DPlate()->setVisible(0);
            getMapOf2DPlateBorder()->setVisible(0);
        }

        else{
            getMapOf2DPlate()->setVisible(1);
            getMapOf2DPlateBorder()->setVisible(1);
        }
    }

    /**
    * Make Infinity Movement
    * -Set Operation to INFINITY
    */
    void BallOnPlate3DVisual::makeInfinityMovement()
    {
        setOperation(OPERATION_INFINITY);
        cout << "Operation: " << getOperation() << endl;
    }

    /**
    * Make Rectangle Movement
    * -Set Operation to RECTANGLE
    */
    void BallOnPlate3DVisual::makeRectangleMovement()
    {
        setOperation(OPERATION_RECTANGLE);
        cout << "Operation: " << getOperation() << endl;
    }

    /**
    * Make Circle Movement
    * -Set Operation to CIRCLE
    */
    void BallOnPlate3DVisual::makeCircleMovement()
    {
        setOperation(OPERATION_CIRCLE);
        cout << "Operation: " << getOperation() << endl;
    }

    /**
     * Update Equilibrium Position with use Mouse Position
     */
    void BallOnPlate3DVisual::updateEquilibriumPosition()
    {
        setOperation(OPERATION_EQUILIBRIUM);
        int x = getMouse()->getX();
        int y = getMouse()->getY();


        int mapX = mapTo(x,32,222,-95,95);
        int mapY = -1*mapTo(y,205,364,-75,75);
        getEquilibrium()->setX(mapX);
        getEquilibrium()->setY(mapY);

        std::cout << "Operation: " << getOperation();
        std::cout << " X" << "=" << mapX << " Y" << "=" << mapY << std::endl;
    }

    /**
     * Update Mouse Position
     *
     * @param newX
     * @param newY
     */
    void BallOnPlate3DVisual::updateMousePosition(int newX, int newY){
        getMouse()->setX(newX);
        getMouse()->setY(newY);
    }

    /**
    * Create Camera
    */
    void BallOnPlate3DVisual::createCamera()
    {
        camera = getSceneManager()->addCameraSceneNode(0, vector3df(-320,320,0), vector3df(1,1,0),false);
    }


    /**
    * Set Irrlicht Device
    */
    void BallOnPlate3DVisual::setDevice()
    {
        device = createDevice( video::EDT_SOFTWARE, core::dimension2d<u32>(SCREEN_X, SCREEN_Y));
        getDevice()->setWindowCaption(L"Gebze Technical University-Ball On Plate 3D");
    }

    /**
     * Set Serial Communication For Windows or For Linux
     *
     * @return SerialCommunication
     */
    void BallOnPlate3DVisual::setSerialCommunication() {

        #ifdef __linux__
          serialCommunication = new SerialCommunicationLinux();
        #elif defined _WIN32 || defined _WIN64
          serialCommunication = new SerialCommunicationWindows();
        #else
        #error "unknown platform"
        #endif

    }

    /**
     * Set KeyIsDown
     */
    void BallOnPlate3DVisual::setKeyIsDown(){
        for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
    }

    /**
    * Check Keyboard For Plate
    */
    void BallOnPlate3DVisual::checkKeyboardForBall(){

        if(IS_KEYBOARD_ACTIVE){

            if(KeyIsDown[irr::KEY_KEY_W] == true){
                core::vector3df ballPosition = getBall()->getBall()->getPosition();

                if(ballPosition.X < 80){
                    ++ballPosition.X;
                    std::cout << "Ball Position X: " <<  ballPosition.X << std::endl;
                    getBall()->getBall()->setPosition(ballPosition);
                }
            }

            else if(KeyIsDown[irr::KEY_KEY_S]){

                core::vector3df ballPosition = getBall()->getBall()->getPosition();

                if(ballPosition.X > -80){
                    --ballPosition.X;
                    std::cout << "Ball Position X: " << ballPosition.X << std::endl;
                    getBall()->getBall()->setPosition(ballPosition);
                }
            }

            if(KeyIsDown[irr::KEY_KEY_A]){
                core::vector3df ballPosition =  getBall()->getBall()->getPosition();

                if(ballPosition.Z < 100){
                    ++ballPosition.Z;
                    std::cout << "Ball Position Z: " << ballPosition.Z << std::endl;
                    getBall()->getBall()->setPosition(ballPosition);
                }
            }

            else if(KeyIsDown[irr::KEY_KEY_D]){
                core::vector3df ballPosition =  getBall()->getBall()->getPosition();

                if(ballPosition.Z > -100){
                    --ballPosition.Z;
                    std::cout << "Ball Position Z: " << ballPosition.Z << std::endl;
                    getBall()->getBall()->setPosition(ballPosition);
                }
            }

        }
    }

    /**
    * Check Keyboard For Ball
    */
    void BallOnPlate3DVisual::checkKeyboardForPlate(){
/*
       if(IS_KEYBOARD_ACTIVE){

            ISceneNode*t = servoMotorYStick;


            core::vector3df Position =  t->getPosition();

            if(KeyIsDown[irr::KEY_UP] == true){
                ++Position.X;

            }

            else if(KeyIsDown[irr::KEY_DOWN]){
                --Position.X;
            }

            if(KeyIsDown[irr::KEY_LEFT]){
                ++Position.Z;
            }

            else if(KeyIsDown[irr::KEY_RIGHT]){
                --Position.Z;

            }

            if(KeyIsDown[irr::   KEY_NUMPAD1]){
                ++Position.Y;
            }

            else if(KeyIsDown[irr::   KEY_NUMPAD2]){
                --Position.Y;
            }

            t->setPosition(Position);




            core::vector3df Rotation =  t->getRotation();

            if(KeyIsDown[irr::KEY_KEY_U] == true){
                ++Rotation.X;

            }

            else if(KeyIsDown[irr::KEY_KEY_J]){
                --Rotation.X;
            }

            if(KeyIsDown[irr::KEY_KEY_I]){
                ++Rotation.Z;
            }

            else if(KeyIsDown[irr::KEY_KEY_K]){
                --Rotation.Z;

            }

            if(KeyIsDown[irr::   KEY_KEY_O]){
                ++Rotation.Y;
            }

            else if(KeyIsDown[irr::   KEY_KEY_L]){
                --Rotation.Y;
            }

            t->setRotation(Rotation);





            core::vector3df Scale =  t->getScale();

            if(KeyIsDown[irr::KEY_KEY_F] == true){
                ++Scale.X;

            }

            else if(KeyIsDown[irr::KEY_KEY_V]){
                --Scale.X;
            }

            if(KeyIsDown[irr::KEY_KEY_G]){
                ++Scale.Z;
            }

            else if(KeyIsDown[irr::KEY_KEY_B]){
                --Scale.Z;

            }

            if(KeyIsDown[irr::   KEY_KEY_H]){
                ++Scale.Y;
            }

            else if(KeyIsDown[irr::   KEY_KEY_N]){
                --Scale.Y;
            }

            t->setScale(Scale);



            std::cout << "********************* " << std::endl;
            std::cout << "Position.X: " << Position.X << std::endl;
            std::cout << "Position.Y: " << Position.Y << std::endl;
            std::cout << "Position.Z: " << Position.Z << std::endl;
            std::cout << "********************* " << std::endl;

            std::cout << "********************* " << std::endl;
            std::cout << "Rotation.X: " << Rotation.X << std::endl;
            std::cout << "Rotation.Y: " << Rotation.Y << std::endl;
            std::cout << "Rotation.Z: " << Rotation.Z << std::endl;
            std::cout << "********************* " << std::endl;

            std::cout << "********************* " << std::endl;
            std::cout << "Scale.X: " << Scale.X << std::endl;
            std::cout << "Scale.Y: " << Scale.Y << std::endl;
            std::cout << "Scale.Z: " << Scale.Z << std::endl;
            std::cout << "********************* " << std::endl;
        }
*/

/*


        if(IS_KEYBOARD_ACTIVE){

            if(KeyIsDown[irr::KEY_UP] == true){
                core::vector3df plateRotation =  getPlate()->getPlate()->getRotation();
                core::vector3df PositionStick =  servoMotorYStick->getPosition();

                if(plateRotation.Z < 13){
                    ++plateRotation.Z;
                    PositionStick.Y = PositionStick.Y + 3;
                    PositionStick.X = PositionStick.X + 3;
                    std::cout << "Plate Rotation Z: " << plateRotation.Z << std::endl;
                    getPlate()->getPlate()->setRotation(plateRotation);
                    servoMotorYStick->setPosition(PositionStick);
                }
            }

            else if(KeyIsDown[irr::KEY_DOWN]){
                core::vector3df plateRotation =  getPlate()->getPlate()->getRotation();
                core::vector3df PositionStick =  servoMotorYStick->getPosition();

                if(plateRotation.Z > -13){
                    --plateRotation.Z;
                    PositionStick.Y = PositionStick.Y - 3;
                    PositionStick.X = PositionStick.X - 3;
                    std::cout << "Plate Rotation Z: " << plateRotation.Z << std::endl;
                    getPlate()->getPlate()->setRotation(plateRotation);
                    servoMotorYStick->setPosition(PositionStick);
                }
            }

            if(KeyIsDown[irr::KEY_LEFT]){
                core::vector3df plateRotation =  getPlate()->getPlate()->getRotation();
                core::vector3df PositionStick =  servoMotorXStick->getPosition();

                if(plateRotation.X < 13){
                    ++plateRotation.X;
                    PositionStick.Y = PositionStick.Y - 3;
                    PositionStick.X = PositionStick.X - 3;
                    std::cout << "Plate Rotation X: " << plateRotation.X << std::endl;
                    getPlate()->getPlate()->setRotation(plateRotation);
                    servoMotorXStick->setPosition(PositionStick);
                }
            }

            else if(KeyIsDown[irr::KEY_RIGHT]){
                core::vector3df plateRotation =  getPlate()->getPlate()->getRotation();
                core::vector3df PositionStick =  servoMotorXStick->getPosition();

                if(plateRotation.X > -13){
                    --plateRotation.X;
                    PositionStick.Y = PositionStick.Y + 3;
                    PositionStick.X = PositionStick.X + 3;
                    std::cout << "Plate Rotation X: " << plateRotation.X << std::endl;
                    getPlate()->getPlate()->setRotation(plateRotation);
                    servoMotorXStick->setPosition(PositionStick);
                }
            }
        }

*/

    }


    /**
     * Create Empty Node
     */
    void BallOnPlate3DVisual::createEmptyNode()
    {
        //emptySceneNode = getSceneManager()->addSphereSceneNode();//scale
    }

}

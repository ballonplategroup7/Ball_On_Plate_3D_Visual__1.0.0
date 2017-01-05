/**
 * BottomPlate
 *
 * File:   BottomPlate.cpp
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

#include "BottomPlate.h"

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
    BottomPlate::BottomPlate(IrrlichtDevice* newDevice,ISceneNode* parentNode)
    {
        setDevice(newDevice);
        createBottomPlate(parentNode);
        setAngleX(DEFAULT_VALUE_ANGLE_X);
        setAngleY(DEFAULT_VALUE_ANGLE_Y);
    }

    /**
     * Create BottomPlate
     */
    void BottomPlate::createBottomPlate(ISceneNode* parentNode){

        bottomPlateSceneNode = getSceneManager()->addCubeSceneNode(10.0f,0,0,
                            vector3df(0, -600, 0),//position
                            vector3df(0, 0, 0),//rotation
                            vector3df(30.0f, 0.01f, 60.0f)); //scale

        bottomPlateSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

        bottomPlateSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/Design/BottomPlate/bottomPlate.png") );

        //  bottomPlateSceneNode->setParent(parentNode);
    }



}

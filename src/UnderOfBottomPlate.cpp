/**
 * UnderOfBottomPlate
 *
 * File:   UnderOfBottomPlate.cpp
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

#include "UnderOfBottomPlate.h"
#include <iostream>

using namespace std;

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
     *  - createUnderOfBottomPlate
     *
     *  @param newDevice
     */
    UnderOfBottomPlate::UnderOfBottomPlate(int object,IrrlichtDevice* newDevice,ISceneNode* parentNode,
                                           double p1, double p2, double p3,
                                           double r1, double r2, double r3,
                                           double s1, double s2, double s3, ITexture* fileName)
    {
        setDevice(newDevice);

        createUnderOfBottomPlate(parentNode, p1, p2, p3, r1, r2, r3, s1, s2, s3, fileName);
    }

    /**
     * Create UnderOfBottomPlate
     */
    void UnderOfBottomPlate::createUnderOfBottomPlate(ISceneNode* parentNode,double p1,double p2,double p3,
                                                                            double r1,double r2,double r3,
                                                                            double s1,double s2,double s3,ITexture* fileName){

        underOfBottomPlateSceneNode = getSceneManager()->addCubeSceneNode(10.0f,0,0,
                            vector3df(p1, p2, p3),//position
                            vector3df(r1, r2, r3),//rotation
                            vector3df(s1, s2, s3)); //scale

        underOfBottomPlateSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

        underOfBottomPlateSceneNode->setMaterialTexture( 0, fileName );

        //  bottomPlateSceneNode->setParent(parentNode);
    }
}

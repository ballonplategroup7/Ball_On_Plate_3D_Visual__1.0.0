
/**
 * Carrier
 *
 * File:   Carrier.cpp
 *
 * Description:
 *
 *  Class for Carrier.
 *  Carrier have:
 *      - ISceneNode Object
 *      - TODO
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#include "Carrier.h"


 namespace
{
    /**
     * For Constant Variables
     *
     */


}

namespace BallOnPlate
{
    /**
     * One Parameter Constructor
     *
     * Call:
     *  - setDevice
     *  - createCarrier
     *
     *  @param newDevice
     */
    Carrier::Carrier(IrrlichtDevice* newDevice)
    {
        setDevice(newDevice);
        createCarrier();
    }

    /**
     * Create Carrier
     */
    void Carrier::createCarrier(){
        //Cube Degisecek konumm tahtanýn tam altýna ayarlanacak
        carrierSceneNode = getSceneManager()->addCubeSceneNode(5.0f,0,0,
                            vector3df(+300, -1000, 0),//position
                            vector3df(0, 0, 0),//rotation
                            vector3df(5.0f, 300.0f, 12.0f)); //scale

        carrierSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

        carrierSceneNode->setMaterialTexture( 0, getVideoDriver()->getTexture("Textures/carrier.png") );
    }

    /**
     * Update Carrier Rotate
     */
    void update(){


    }
}

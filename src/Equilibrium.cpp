/**
 * Equilibrium
 *
 * File:   Equilibriums.cpp
 *
 * Description:
 *
 *  Class for Equilibriums.
 *  Equilibriums have:
 *      - Point X
 *      - Point Y
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#include "Equilibrium.h"

 namespace
{
    /**
     * For Constant Variables
     *
     */
    const static int FIRST_EQUILIBRIUM_POSITION_X= 0; //  First Equilibrium Position X
    const static int FIRST_EQUILIBRIUM_POSITION_Y= 0; //  First Equilibrium Position Y
}

namespace BallOnPlate
{
    /**
     * Default Constructor
     *
     * Call:
     *   - setX
     *   - setY
     */
    Equilibrium::Equilibrium()
    {
        setX(FIRST_EQUILIBRIUM_POSITION_X);
        setY(FIRST_EQUILIBRIUM_POSITION_Y);
    }
}

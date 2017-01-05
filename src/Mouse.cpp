/**
 * Mouse
 *
 * File:   Mouse.cpp
 *
 * Description:
 *
 *  Class for Mouse.
 *  Mouse have:
 *      - X
 *      - Y
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

 namespace
{
    /**
     * For Constant Variables
     *
     */
    const static int DEFAULT_POSITION_X = 0; //  Default position x
    const static int DEFAULT_POSITION_Y = 0; //  Default position y
}

#include "Mouse.h"
namespace BallOnPlate
{
    /**
     * Default Constructor
     *
     * Call:
     *   - setX
     *   - setY
     */
    Mouse::Mouse()
    {
        setX(DEFAULT_POSITION_X);
        setY(DEFAULT_POSITION_Y);
    }
}

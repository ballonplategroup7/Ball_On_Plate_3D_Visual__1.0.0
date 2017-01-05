/**
 * Mouse
 *
 * File:   Mouse.h
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


#ifndef MOUSE_H
#define MOUSE_H

namespace BallOnPlate
{
    class Mouse
    {
        public:

            /**
            * Default Constructor
            *
            * Call:
            *   - setX
            *   - setY
            */
            Mouse();

            /**
             * Get Mouse Point X
             *
             * @return Mouse Point X
             */
            int getX() {return X;}

            /**
             * Set Mouse Point X
             *
             * @param newValue for Mouse Point X
             */
            void setX(int newValue) {X = newValue;}

            /**
             * Get Mouse Point Y
             *
             * @return Mouse Point Y
             */
            int getY() {return Y;}

            /**
             * Set Mouse Point Y
             *
             * @param newValue for Mouse Point Y
             */
            void setY(int newValue) {Y = newValue;}

        private:

            int X;    /** Mouse Point X */
            int Y;    /** Mouse Point Y */
    };
}

#endif // MOUSE_H

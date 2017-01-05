/**
 * Equilibrium
 *
 * File:   Equilibriums.h
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

#ifndef EQUILIBRIUM_H
#define EQUILIBRIUM_H


namespace BallOnPlate
{
    class Equilibrium
    {
        public:

            /**
            * Default Constructor
            *
            * Call:
            *   - setX
            *   - setY
            */
            Equilibrium();

            /**
             * Get Equilibrium Point X
             *
             * @return Equilibrium Point X
             */
            int getX() {return X;}

            /**
             * Set Equilibrium Point X
             *
             * @param newValue for Equilibrium Point X
             */
            void setX(int newValue) {X = newValue;}

            /**
             * Get Equilibrium Point Y
             *
             * @return Equilibrium Point Y
             */
            int getY() {return Y;}

            /**
             * Set Equilibrium Point Y
             *
             * @param newValue for Equilibrium Point Y
             */
            void setY(int newValue) {Y = newValue;}

        private:

            int X;    /** Equilibrium Point X */
            int Y;    /** Equilibrium Point Y */
    };
}

#endif // EQUILIBRIUM_H

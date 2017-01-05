/**
 * Serial Communication
 *
 * File:   SerialCommunicationWindows.h
 *
 * Description:
 *
 *  Class for Serial Communication Windows.
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifdef _WIN32

#ifndef SERIALCOMMUNICATIONWINDOWS_H
#define SERIALCOMMUNICATIONWINDOWS_H


#include "SerialCommunication.h"
#include <windows.h>     /** Serial Communication For Windows */


namespace BallOnPlate
{
    class SerialCommunicationWindows: public SerialCommunication
    {
        public:

            /**
             * No Parameter Constructor
             *
             * Call createConnectForSerialCommunication
             */
            SerialCommunicationWindows();

            /**
             * Take Inputs From Arduino:
             *  - Ball Position X (int)
             *  - Ball Position Y (int)
             *  - Plate Angle x (double)
             *  - Plate Angle y (double)
             *
             * @param ball
             * @param plate
             */
            void takeInputsFromArduino(Ball *ball, Plate *plate);

            /**
             * Send Inputs To Arduino:
             *  - Operation (int)
             *  - Equilibrium Position X (int)
             *  - Equilibrium Position Y (int)
             *
             * @param operation
             * @param equilibrium
             */
            void sendOutputsToArduino(int operation, Equilibrium equilibrium);

            /**
             * Send Inputs To Arduino Connect End
             *
             */
            void sendOutputsToArduinoConnectEnd();

            /**
             * Create Connect For Serial Communication
             */
            void createConnectForSerialCommunication();

        private:

            /**
             * Set handlerSerial
             */
            void setHandlerSerial(HANDLE newHandlerSerial) {handlerSerial = newHandlerSerial;}

            /**
             * Get HandlerSerial
             *
             * @return Handle Serial
             */
            HANDLE getHandlerSerial() {return handlerSerial;}

            /** Data Field */
            HANDLE handlerSerial;      /** Serial comm handler   */

    };
}

#endif // SERIALCOMMUNICATIONWINDOWS_H


#endif // defined

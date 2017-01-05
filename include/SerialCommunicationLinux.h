/**
 * Serial Communication
 *
 * File:   SerialCommunicationLinux.h
 *
 * Description:
 *
 *  Class for Serial Communication Linux.
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */
 #ifdef __linux__
#ifndef SERIALCOMMUNICATIONLINUX_H
#define SERIALCOMMUNICATIONLINUX_H

#include "SerialCommunication.h"

namespace BallOnPlate
{
    class SerialCommunicationLinux: public SerialCommunication
    {
        public:

            /**
             * No Parameter Constructor
             *
             * Call createConnectForSerialCommunication
             */
            SerialCommunicationLinux();

			 /**
             * Destructor
             */
			~SerialCommunicationLinux();

            int set_interface_attribs (int fd, int speed, int parity);

            void set_blocking (int fd, int should_block);

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

            /** Data Field */
            int fd;

    };
}

#endif // SERIALCOMMUNICATIONLINUX_H

#endif

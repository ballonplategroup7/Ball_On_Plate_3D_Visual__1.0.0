/**
 * Serial Communication
 *
 * File:   SerialCommunication.h
 *
 * Description:
 *
 *  Class for Serial Communication.
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H


#include <bits/stdc++.h> /** For Detecting Operating System */

#include "Ball.h"
#include "Plate.h"
#include "Equilibrium.h"

#include <iostream>
#include <string>
#include <sstream>

namespace BallOnPlate
{
    class SerialCommunication
    {
        public:
            /**
             * No Parameter Constructor
             *
             * Call detectOperatingSystem
             */
            SerialCommunication();

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
            virtual void takeInputsFromArduino(Ball *ball, Plate *plate){;}

            /**
             * Send Inputs To Arduino:
             *  - Operation (int)
             *  - Equilibrium Position X (int)
             *  - Equilibrium Position Y (int)
             *
             * @param operation
             * @param equilibrium
             */
            virtual void sendOutputsToArduino(int operation, Equilibrium equilibrium){;}

           /**
             * Send Inputs To Arduino Connect End
             *
             */
            virtual void sendOutputsToArduinoConnectEnd(){;}

            /**
             * Create Connect For Serial Communication
             */
            virtual void createConnectForSerialCommunication(){;}

            /**
             * Split The Inputs String For Take Inputs From Arduino
             *
             * @param ball
             * @param plate
             * @param inputString
             */
            void splitTheInputsStringForTakeInputsFromArduino(Ball *ball, Plate *plate, std::string inputString);

            /**
             * Make A String For Send Outputs To Arduino
             *
             * @param operation
             * @param equilibrium
             */
            std::string makeAStringForSendOutputsToArduino(int operation, Equilibrium equilibrium);

            /**
             * Set OperatingSystem
             *
             * @param newOperatingSystem
             */
            void setOperatingSystem(int newOperatingSystem) {operatingSystem = newOperatingSystem;}

            /**
             * Get OperatingSystem
             *
             * @return which operating system works
             */
            int getOperatingSystem() {return operatingSystem;}

            /**
             * Set Connected
             *
             * @param newConnected
             */
            void setConnected(bool newConnected) {connected = newConnected;}

            /**
             * Get Connected
             *
             * @return Connected
             */
            bool getConnected() {return connected;}

            /**
             * Set Arduino Mode Visual
             *
             * @param newArduinoModeVisual
             */
            void setArduinoModeVisual(bool newArduinoModeVisual) {arduinoModeVisual = newArduinoModeVisual;}

            /**
             * Get Arduino Mode Visual
             *
             * @return Arduino Mode Visual
             */
            bool getArduinoModeVisual() {return arduinoModeVisual;}

        private:

           /**
            * For Detecting Operating System
            *
            * Set OperatingSystem
            */
            void detectOperatingSystem();

            /** Data Field */

            int operatingSystem;       /** Operating System      */
            bool connected;            /** Connection status     */
            bool arduinoModeVisual;    /** Connection status     */
    };
}

#endif // SERIALCOMMUNICATION_H

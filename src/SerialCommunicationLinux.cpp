/**
 * SerialCommunication
 *
 * File:   SerialCommunicationLinux.cpp
 *
 * Description:
 *
 *  Class for SerialCommunication Linux.
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */
 #ifdef __linux__
#include "SerialCommunicationLinux.h"


/** For uint8_t */
#include <stdint.h>
#include <inttypes.h>

#define ARDUINO_WAIT_TIME 2000

#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "rs232.h"
 namespace
{
    /**
     * For Constant Variables
     *
     */
     const static int PORT_NUMBER=24;
     const static int BAUD=115200;
}

namespace BallOnPlate
{
    /**
     * No Parameter Constructor
     *
     * Call createConnectForSerialCommunication
     */
    SerialCommunicationLinux::SerialCommunicationLinux()
    {
        createConnectForSerialCommunication();
    }

    /**
     * Destructor
     */
    SerialCommunicationLinux::~SerialCommunicationLinux()
    {
        RS232_CloseComport(PORT_NUMBER);
    }


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
    void SerialCommunicationLinux::takeInputsFromArduino(Ball *ball, Plate *plate){

        /** Check if we are actually connected */
        if(getConnected()){

            int cport = getCport(PORT_NUMBER);

            std::string takenInputsString;
            char aa[19];

            int n = 0;

            while(n < 18)
            {
                n += read(cport, &aa[n], sizeof aa);
                if(aa[0] == '!'){
                    setArduinoModeVisual(false);
                    n = 18;
                }else{
                    setArduinoModeVisual(true);
                }
            }

            /** Make a string */
            takenInputsString.append(aa);

            /** Split the Inputs String */
            if(getArduinoModeVisual())
                splitTheInputsStringForTakeInputsFromArduino(ball,plate,takenInputsString.substr(0,18));
        }
    }

    /**
     * Send Inputs To Arduino:
     *  - Operation (int)
     *  - Equilibrium Position X (int)
     *  - Equilibrium Position Y (int)
     *
     * @param operation
     * @param equilibrium
     */
    void SerialCommunicationLinux::sendOutputsToArduino(int operation, Equilibrium equilibrium){

        /** Check if we are actually connected */
        if(getConnected()){

           if(getArduinoModeVisual()){

                int cport = getCport(PORT_NUMBER);

                char outData[13];

                /** Make A String */
                std::string temp = makeAStringForSendOutputsToArduino(operation,equilibrium);

                for(int i=0; i<12; ++i)
                    outData[i] = temp.at(i);

                write(cport, outData, sizeof(char) * 12);
            }
        }
    }

    /**
     * Send Inputs To Arduino Connect End
     *
     */
    void SerialCommunicationLinux::sendOutputsToArduinoConnectEnd(){

        int cport = getCport(PORT_NUMBER);
        char outData[2] = "!";

        write(cport, outData, sizeof(char) * 1);
    }

    /**
     * Create Connect For Serial Communication
     */
    void SerialCommunicationLinux::createConnectForSerialCommunication(){

        /** We're not yet connected */
        setConnected(false);

        //device = createDevice( video::EDT_SOFTWARE, core::dimension2d<u32>(SCREEN_X, SCREEN_Y));

        int cport_nr=PORT_NUMBER;       /** /dev/ttyACM0 */
        int bdrate= BAUD;               /** Baud: 9600   */
        char mode[]={'8','N','1',0};    /** Mode         */

        if(RS232_OpenComport(cport_nr, bdrate, mode))
        {
            printf("Can not open comport\n");
        }else{
            setConnected(true);
            setArduinoModeVisual(true);
        }
    }

}


#endif

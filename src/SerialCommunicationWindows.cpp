/**
 * SerialCommunication
 *
 * File:   SerialCommunicationWindows.cpp
 *
 * Description:
 *
 *  Class for SerialCommunication Windows.
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#include "SerialCommunicationWindows.h"

#ifdef _WIN32


/** For uint8_t */
#include <stdint.h>
#include <inttypes.h>

#define ARDUINO_WAIT_TIME 2000

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
     * No Parameter Constructor
     *
     * Call createConnectForSerialCommunication
     */
    SerialCommunicationWindows::SerialCommunicationWindows()
    {
        createConnectForSerialCommunication();
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
    void SerialCommunicationWindows::takeInputsFromArduino(Ball *ball, Plate *plate){

        /** Check if we are actually connected */
        if(getConnected()){
                DWORD bytesRead;
                std::string takenInputsString;
                bool check = true;
                char tempCharacter;

                /** Take Inputs */
                while (check==true){

                    ReadFile(getHandlerSerial(), &tempCharacter, sizeof(char), &bytesRead, NULL);
                    takenInputsString += tempCharacter;

                    if(tempCharacter == '$'){
                        check = false;
                    }
                }

                std::cout << takenInputsString << std::endl;


                if(takenInputsString.at(0) == '!'){
                    setArduinoModeVisual(false);
                }else{
                    setArduinoModeVisual(true);
                }

                /** Split the Inputs String */
                if(getArduinoModeVisual())
                    splitTheInputsStringForTakeInputsFromArduino(ball,plate,takenInputsString);
                else
                    splitTheInputsStringForTakeInputsFromArduino(ball,plate,takenInputsString.substr(1,takenInputsString.length()));

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
    void SerialCommunicationWindows::sendOutputsToArduino(int operation, Equilibrium equilibrium){

        /** Check if we are actually connected */
        if(getConnected()){

           if(getArduinoModeVisual()){

                DWORD bytesSend;
                char outData[13];

                /** Make A String */
                std::string temp = makeAStringForSendOutputsToArduino(operation,equilibrium);

                for(int i=0; i<12; ++i)
                    outData[i] = temp.at(i);

                /** And Send It */
                BOOL retVal = WriteFile(getHandlerSerial(), outData, sizeof(char)*12, &bytesSend, NULL);
                if (!retVal) {
                    printf("Error Writing File");
                }

            }
        }
    }

    /**
     * Send Inputs To Arduino Connect End
     *
     */
    void SerialCommunicationWindows::sendOutputsToArduinoConnectEnd(){

        DWORD bytesSend;
        char outData[2] = "!";
        BOOL retVal = WriteFile(getHandlerSerial(), outData, sizeof(char), &bytesSend, NULL);
        if (!retVal) {
            printf("Error Writing File");
        }
    }

    /**
     * Create Connect For Serial Communication
     */
    void SerialCommunicationWindows::createConnectForSerialCommunication(){

        char portName[13] = "\\\\.\\COM10";
      /*  int port;

        std::cout << "Give The Port: ";

        std::cin >> port;

        if(port == 0){
          portName[7] = '0';
          portName[8] = '\0';
        }else if(port == 1){
          portName[7] = '1';
          portName[8] = '\0';
        }else if(port == 2){
          portName[7] = '2';
          portName[8] = '\0';
        }else if(port == 3){
          portName[7] = '3';
          portName[8] = '\0';
        }else if(port == 4){
          portName[7] = '4';
          portName[8] = '\0';
        }else if(port == 5){
          portName[7] = '5';
          portName[8] = '\0';
        }else if(port == 6){
          portName[7] = '6';
          portName[8] = '\0';
        }else if(port == 7){
          portName[7] = '7';
          portName[8] = '\0';
        }else if(port == 8){
          portName[7] = '8';
          portName[8] = '\0';
        }else if(port == 9){
          portName[7] = '9';
          portName[8] = '\0';
        }else if(port > 9 && port < 100){
            int ones = port%10;
            int tens = port/10;

            char charOnes = '0' + ones;
            char charTens = '0' + tens;

            portName[7] = charTens;
            portName[8] = charOnes;
            portName[9] = '\0';
        }*/


        //We're not yet connected
        setConnected(false);

        //Try to connect to the given port throuh CreateFile
        setHandlerSerial(CreateFile(portName,
                GENERIC_READ | GENERIC_WRITE,
                0,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL));

        //Check if the connection was successfull
        if(getHandlerSerial()==INVALID_HANDLE_VALUE)
        {
            //If not success full display an Error
            if(GetLastError()==ERROR_FILE_NOT_FOUND){

                //Print Error if neccessary
                printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

            }
            else
            {
                printf("ERROR!!!");
            }
        }
        else
        {
            //If connected we try to set the comm parameters
            DCB dcbSerialParams = {0};

            //Try to get the current
            if (!GetCommState(getHandlerSerial(), &dcbSerialParams))
            {
                //If impossible, show an error
                printf("failed to get current serial parameters!");
            }
            else
            {
                //Define serial connection parameters for the arduino board
                dcbSerialParams.BaudRate=CBR_115200;
                dcbSerialParams.ByteSize=8;
                dcbSerialParams.StopBits=ONESTOPBIT;
                dcbSerialParams.Parity=NOPARITY;
                //Setting the DTR to Control_Enable ensures that the Arduino is properly
                //reset upon establishing a connection
                dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

                 //Set the parameters and check for their proper application
                 if(!SetCommState(getHandlerSerial(), &dcbSerialParams))
                 {
                    printf("ALERT: Could not set Serial Port parameters");
                 }
                 else
                 {
                     //If everything went fine we're connected
                     setConnected(true);
                     setArduinoModeVisual(true);
                     //Flush any remaining characters in the buffers
                     PurgeComm(getHandlerSerial(), PURGE_RXCLEAR | PURGE_TXCLEAR);
                     //We wait 2s as the arduino board will be reseting
                     Sleep(ARDUINO_WAIT_TIME);
                 }
            }
        }

        if (getConnected())
            std::cout << "We're connected\n";
    }

}

#endif

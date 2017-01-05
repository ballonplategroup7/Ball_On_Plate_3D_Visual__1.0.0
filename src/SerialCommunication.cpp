/**
 * SerialCommunication
 *
 * File:   SerialCommunication.cpp
 *
 * Description:
 *
 *  Class for SerialCommunication.
 *
 * @author CSE_395_Undergraduate_Project_I_Group_7
 * @since Friday 28 October 2016
 */

#include "SerialCommunication.h"

 namespace
{
    /**
     * For Constant Variables
     *
     */

    const static int OPERATING_SYSTEM_WINDOWS = 1; /**  Value of operating system Windows  */
    const static int OPERATING_SYSTEM_LINUX   = 2; /**  Value of operating system Linux    */
}

namespace BallOnPlate
{
    /**
     * No Parameter Constructor
     *
     * Call detectOperatingSystem
     */
    SerialCommunication::SerialCommunication()
    {
        detectOperatingSystem();
    }

    /**
     * Split The Inputs String For Take Inputs From Arduino
     *
     * @param ball
     * @param plate
     * @param inputString
     */
    void SerialCommunication::splitTheInputsStringForTakeInputsFromArduino(Ball *ball, Plate *plate, std::string inputString){

       /**
        *  input string: +ballPositionX_+ballPositionY_platePositionX_platePositionY$
        *
        *  for example : +073_-045_004_103$ then make
        *         set Ball  Current X--> 73
        *         set Ball  Current Y--> -45
        *         set Plate Angle X--> 4
        *         set Plate Angle Y--> 103
        *
        *   hint: Use '_' and '$' for split
        */

        int number[4];
        int i=0;
    	std::istringstream iss(inputString);
    	std::string token;
    	while (std::getline(iss, token, '_'))
    	{
    	    number[i] = std::atoi(token.c_str());
            ++i;
   	 	}

   	 	if(number[0] == 999)
            ball->getBall()->setVisible (false);
        else
            ball->getBall()->setVisible (true);
   	 	ball->setCurrentX(number[0]);
   	 	ball->setCurrentY(number[1]);
   	 	plate->setAngleX(number[2]);
   	 	plate->setAngleY(number[3]);
    }

    /**
     * Make A String For Send Outputs To Arduino
     *
     * @param operation
     * @param equilibrium
     */
    std::string SerialCommunication::makeAStringForSendOutputsToArduino(int operation, Equilibrium equilibrium){

      /**
        *  string: operation_equilibriumPositionX_equilibriumPositionY
        *
        *  for example : operation-->101  equilibriumPositionX --> 73  equilibriumPositionY --> 5     then make  1_+073_+005$
        *  for example : operation-->102  equilibriumPositionX --> 2   equilibriumPositionY --> -55   then make  2_+002_-055$
        *  for example : operation-->103  equilibriumPositionX --> -163 equilibriumPositionY --> 103  then make  3_-163_+103$
        *
        *  don't forget adding '$'
        */

        const std::string zero = "0";
        const std::string plus  = "+";
        const std::string minus = "-";
        const std::string end = "$";
        const std::string delimeter = "_";
        std::string temp;
        std::stringstream skip;

        int i, j, len;
        int number[3];

        number[0] = operation;
        number[1] = equilibrium.getX();
        number[2] = equilibrium.getY();

        int k = number[0] % 100;
        skip << k;
        temp.append(skip.str());
        temp.append(delimeter);

        for(i=1; i<3; ++i){
            if(number[i] >= 0){
                temp.append(plus);
            }
            else{
                temp.append(minus);
                number[i] = -number[i];
            }
            std::stringstream skip1;
            skip1 << number[i];
            len = skip1.str().size();

            for(j=0; j<3-len; ++j){
                temp.append(zero);
            }
            temp.append(skip1.str());
            temp.append(delimeter);
        }

        temp = temp.substr(0, temp.size()-1);
        temp.append(end);

        //std::cout << temp << '\n';

        return temp;

    }

    /**
     * For Detecting Operating System
     *
     * Set OperatingSystem
     */
    void SerialCommunication::detectOperatingSystem(){

        #ifdef __linux__
          setOperatingSystem(OPERATING_SYSTEM_LINUX);
        #elif defined _WIN32 || defined _WIN64
          setOperatingSystem(OPERATING_SYSTEM_WINDOWS);
        #else
        #error "unknown platform"
        #endif
    }

}

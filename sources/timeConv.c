#include "../headers/timeConv.h"

int* convTime(double dTimePassed)
{
    static int iRetVal[4];
    int iTimeTaken;
    iRetVal[0] = 0; /*Hours*/
    iRetVal[1] = 0; /*Hours Remainder*/
    iTimeTaken = dTimePassed; /*Get time into an integer*/
    
    iRetVal[0] = iTimeTaken / 3600;
    iRetVal[1] = iTimeTaken % 3600;
    iRetVal[2] = iRetVal[1] / 60; /*Get minutes*/
    iRetVal[3] = iRetVal[1] % 60; /*Get seconds*/
    /* printf("\n\tThat took %d hours %d minutes and %d seconds\n\n", iHours, iMinutes, iSeconds); */ 
	
	return iRetVal;    
}
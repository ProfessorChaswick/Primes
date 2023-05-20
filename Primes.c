#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <locale.h>
#include "headers\timeConv.h"

int main(void)
{
	setlocale(LC_ALL, "en_US");
    int iTop, iMax, iNum, iCount;
    char answer;
	clock_t timeOfDay;
	printf("Please, enter highest number to which to search:  ");
	scanf("%d", &iTop);
	printf("You entered %'d.\n", iTop);
	iMax = floor(sqrt(iTop)); 
	
	printf("This will run through %'d, the floor of the square root of %'d.\n", iMax, iTop);
	int *nums = (int*)malloc(iTop * sizeof(int)+16); /*allocate memory for an array: nums*/
	timeOfDay = clock();
	for(iNum = 0; iNum <= iTop + 1; iNum ++)
		nums[iNum] = iNum; /* Populate the array */

    nums[1] = 0; /*eliminate #1*/
	int iChk;
    iCount = 0;
	for(int iZed = 2; iZed <= iMax; iZed ++)
	{
		iChk = iZed;
		do
		{
			if(nums[iChk] % iZed == 0 && nums[iChk] != iZed)
                nums[iChk] = 0; /* If a divisor other than one and itself is found, change the value to zero */
			iChk++;
		}while(iChk <= iTop);
	}
    for(int x = 0; x <= iTop; x++)
    {
        if(nums[x]!=0)
            iCount++;
    }
	timeOfDay = clock() - timeOfDay;
    printf("\nThere are %'d prime numbers below %'d.\n", iCount, iTop);
    printf("Would you like them listed here? Y/N: ");
    scanf(" %c", &answer);
    if(answer=='Y' || answer=='y')
    {
        for(int x = 0; x <= iTop; x++)
	    {
		    if(nums[x] != 0)
			    printf("%'d is prime\n", nums[x]); /* print all the numbers > 0 as they are all prime */
	    }
    }
	
	free(nums); /* dispose of (free up) memory allocated */
	
	double dTimeTaken = ((double)timeOfDay) / CLOCKS_PER_SEC; /* calculate and report time taken finding primes */
	int* elasped = convTime(dTimeTaken);
    
    printf("\n\tThat took %d hours %d minutes and %d seconds\n\n", elasped[0], elasped[2], elasped[3]); 
	
	return 0;
}

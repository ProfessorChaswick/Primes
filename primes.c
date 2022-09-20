#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "en_US");
    int iTop, iMax, iNum, iTopInt;
	clock_t t;
	printf("Please, enter highest number to which to search:  ");
	scanf("%d", &iTop);
	iTopInt = iTop;
	printf("You entered %'d.\n", iTop);
	iMax = floor(sqrt(iTop)); 
	
	printf("This will run through %'d, the floor of the square root of %'d.\n", iMax, iTop);
	int *nums = malloc(iTopInt * sizeof(int));
	t = clock();
	for(iNum = 0; iNum <= iTopInt + 1; iNum ++)
		nums[iNum] = iNum;

    nums[1] = 0; /*eliminate 1 and 2*/
	nums[2] = 0;
	int iChk;
	for(int iZed = 2; iZed <= iMax; iZed ++)
	{
		iChk = iZed;
		do
		{
			if(nums[iChk] % iZed == 0 && nums[iChk] != iZed)
				nums[iChk] = 0;
			iChk++;
		}while(iChk <= iTop);
	}
	t = clock() - t;
	for(int x = 0; x <= iTop; x++)
	{
		if(nums[x] != 0)
			printf("%'d is prime\n", nums[x]);
	}
	free(nums);
	double dTimeTaken = ((double)t) / CLOCKS_PER_SEC;
    /*************************/
    int iHours, iHoursRem, iMinutes, iSeconds;
    int iTimeTaken;
    iHours = 0;
    iHoursRem = 0;
    iTimeTaken = dTimeTaken;
    
    iHours = iTimeTaken / 3600;
    iHoursRem = iTimeTaken % 3600;
    iMinutes = iHoursRem / 60;
    iSeconds = iHoursRem % 60;
    /*************************/
	printf("\n\tThat took %d hours %d minutes and %d seconds\n\n", iHours, iMinutes, iSeconds); 
}

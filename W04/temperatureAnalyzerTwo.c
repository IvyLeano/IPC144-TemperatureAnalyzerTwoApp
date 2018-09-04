/* W04
 * temperatureAnalyzerTwo.c
 * Ivy Leano
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MINDAYS 3
#define MAXDAYS 10

int main(void) 
{
	int i;
	int days;
	int high[MAXDAYS];
	int low[MAXDAYS];
	int lowestTemp = 0;
	int highestTemp = 0;
	int counter = 0;
	int highestTempDay = 0;
	int lowestTempDay = 0;
	int numDays = 0;
	double averageTemp = 0;
	double sumAverageTemp;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	
	// Prompts user to input number of days between MINDAYS and MAXDAYS

	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	scanf("%d", &days);
	printf("\n");

	// While-construct used to avoid incorrect input
	// Re-prompts input for days variable if incorrect

	while (days < MINDAYS || days > MAXDAYS) 
	{
		printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
		scanf("%d", &days);
		printf("\n");
	}

	// For-construct iterates through days, prompts user for low and high temperature input

	for (i = 0; i < days; i++) 
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	// First row (header) for data chart

	printf("\n");
	printf("Day  Hi  Low\n");

	// For-construct, rows for data chart - day, high, low

	for (i = 0; i < days; i++) 
	{
		printf("%-4d %-3d %3d\n", i + 1, high[i], low[i]);
	}

	// For-construct for highest and lowest temperature storing, and day counter

	for (i = 0; i < days; i++) 
	{
		counter++;

		if (high[i] > highestTemp) 
		{
			highestTemp = high[i];
			highestTempDay = counter;
		}

		if (low[i] <= low[0]) 
		{
			lowestTemp = low[i];
			lowestTempDay = counter;
		}
	}

	// Highest temperature and lowest temperature outputs

	printf("\n");
	printf("The highest temperature was %d, on day %d", highestTemp, highestTempDay);
	printf("\n");
	printf("The lowest temperature was %d, on day %d", lowestTemp, lowestTempDay);
	printf("\n");

	// While-construct allows users to retrieve data for a given day

	while (numDays >= 0) 
	{
		printf("\n");
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &numDays);
		
		// While-construct used to verify that user input is between 1 and value of user input for days

		while (numDays > days || numDays == 0)
		{
			printf("\n");
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &numDays);
		}

		if (numDays < 0)
		{
			printf("\n");
			printf("Goodbye!");
			printf("\n");
		}

		// For-construct iterates through days, displaying average temperature and the sum of average temperatures

		else if (numDays > 0)
		{
			sumAverageTemp = 0;

			for (i = 0; i < numDays; i++)
			{
				averageTemp = low[i] + high[i];
				sumAverageTemp += averageTemp;
			}

			printf("\n");
			printf("The average temperature up to day %d is: %.2f", numDays, sumAverageTemp / (numDays * 2));
			printf("\n");
		}
	}

	return 0;
}



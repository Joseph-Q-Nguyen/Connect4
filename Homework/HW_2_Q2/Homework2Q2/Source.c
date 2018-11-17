// Question 2 for HW2
// Author: Joseph Nguyen

#include <stdio.h>
#include <math.h>
int main() {
	double temp;
	double cel = 0;
	printf("Please enter a temperature in Fahrenheit: ");
	scanf_s("%lf", &temp);
	cel = temp - 32;
	cel *= .5556;
	cel = round(cel);
	printf("Your temperature in Celsisus is: %.0lf\n", cel);
	if (temp > 212)
		printf("Temperature is boiling");
	else if (temp > 90)
		printf("Temperature is hot.");
	else if (temp > 60)
		printf("Temperature is good.");
	else if (temp > 32)
		printf("Temperature is cold.");
	else
		printf("Temperature is freezing.");
	printf("\n");
	system("pause");
	return 0;
}
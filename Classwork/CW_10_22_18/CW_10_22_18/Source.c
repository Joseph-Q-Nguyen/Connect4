#include <stdio.h>
#include <math.h>
void circumference(double);
void area(double);
void volume(double);

const double pi = 3.14;

int main(void) {
	void (*f[3])(double) = {circumference, area, volume};
	double radius;
	int choice;
	printf("Enter 0 to calculate the circumference of a circle.\n"
		"Enter 1 to calculate the area of a circle.\n"
		"Enter 2 to calculate the volume of a sphere.\n");
	scanf_s("%d", &choice);
	printf("Enter a radius ");
	scanf_s("%lf", &radius);
	(*f[choice])(radius);
	system("pause");
}

void circumference(double radius) {
	printf("The cirucumference of a circle with radius %.2f is %.2f\n\n", radius, 2 * pi * radius);
}

void area(double radius) {
	printf("The area of a circle with radius %.2f is %.2f\n\n", radius, pi * radius * radius);
}

void volume(double radius) {
	printf("The volume of a sphere with radius %.2f is %.2f\n\n", radius, 3.0/4.0 * pi * pow(radius, 3));
}
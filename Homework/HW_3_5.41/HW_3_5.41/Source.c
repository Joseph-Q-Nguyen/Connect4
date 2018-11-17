#include<stdio.h>
#include<math.h>
double distance(int, int, int, int);

int main()
{
	int x1 = 1;
	int y1 = 1;

	int x2 = 3;
	int y2 = 3;

	printf("%lf\n", distance(x1, y1, x2, y2));

	system("pause");
	return 0;
}

double distance(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	double num = (deltaX * deltaX) + (deltaY * deltaY);
	return sqrt(num);
}
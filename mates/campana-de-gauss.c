#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



double f(double x)
{
	float media = 0, sigma = 1;

	double euler_exponent = -(1 / 2.0) * (powl(x - media, 2) / sigma);

	double left_part = 1 / (sqrtl(2 * M_PI) * sigma);
	double right_part = powl(M_E, euler_exponent);

	return left_part * right_part;
}


int main(int argc, char *argv[])
{
	float sigma, media, x;
	char opcion[10];

	printf(" Media: ");
	scanf("%f", &media);

	printf(" Varianza: ");
	scanf("%f", &sigma);

	printf(" X: ");
	scanf("%f", &x);

	float z = (x - media) / sigma;

	if (media > x)
		z *= -1;

	double res = 0.5;
	double rects_width = 0.00000085f;

	for (float x = 0; x < z; x += rects_width) 
	{
		res += f(x) * rects_width;
	}

	if (z < media)
		res = 1 - res;


	printf(" El resultado es: %.4lf\n", res);

	return 0;
}

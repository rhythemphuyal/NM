#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float);
int main()
{
	float xu = 0, xl = 1, xm, err, epsilon = 0.0001, counter =  0;
	printf (" Enter Xu = ");
	scanf ("%f",&xu);
	printf (" Enter Xl = ");
	scanf ("%f",&xl);
	printf (" Initial functional values: \n");
	printf (" f(%.4f) = %f \n", xu, f(xu));
	printf (" f(%.4f) = %f \n", xl, f(xl));
	printf (" epsilon = %f \n\n", epsilon);
	
	if (f(xu) + f(xl) > 0)
	{
		printf (" Error! f(Xu) and f(Xl) do not have opposite signs. \n\n");
	}
	
	xm = (xu + xl)/2;
	printf (" Xu \t\t f(Xu) \t\t Xl \t\t f(Xl) \t\t Xm \t\t f(Xm) \t\t ERROR \n");
	
	while (counter < 20.0 && fabs (f(xm)) > epsilon)
	{
		xm = (xu + xl) / 2;
		err = (xm - xu) / xm;
		printf (" %f \t %f \t %f \t %f \t %f \t %f \t %f \n", xu, f(xu), xl, f(xl), xm, f(xm), err);
		
		if (f(xu) + f(xm) < 0)
		{
			xl = xm;
		}
		else 
		{
			xu = xm;
		}
		counter++;
	}
	
	printf ("\n Number of iterations performed = %.0f \n", counter);
	printf (" ROOT = %f \n\n", xm);
	return 0;
}

float f (float x)
{
	float val;
	val = 2 * pow (x,3) - 5;
	return val;
}


#include <math.h>
#include <stdio.h>

void my_sincos(double x, double y[2], int n){
	int i;
	long long fact;
	double tmp;
	y[0] = y[1] = 0;
	for(i = 0, fact = 1, tmp = 1; i < n; fact *= ++i){
		y[i & 1] += tmp / fact * (1 - (i & 2));
		tmp *= x;
	}
}

double my_exp(double x, int n){
	int i;
	long long fact;
	double rtn;
	double tmp;
	for(i = 0, fact = 1, rtn = 0, tmp = 1; i < n; fact *= ++i){
		rtn += tmp / fact;
		tmp *= x;
	}
	return rtn;
}

int main(){
	double x;
	for(x = 0; x < 10; x += .1){
		double my_y[2];
		my_sincos(x, my_y, 15);
		printf("sin(%f) my:%f - math.h:%f = %e\n", x, my_y[1], sin(x), my_y[1] - sin(x));
		printf("cos(%f) my:%f - math.h:%f = %e\n", x, my_y[0], cos(x), my_y[0] - cos(x));
	}
	for(x = 0; x < 10; x += .1){
		double my_y = my_exp(x, 15);
		printf("exp(%f) my:%f - math.h:%f = %e\n", x, my_y, exp(x), my_y - exp(x));
	}

}

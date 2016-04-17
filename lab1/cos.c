#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846


double cost(double x, double prec) {
        double sum = 0.0;
        double el = 1e3;
        double licz = 1.0;
        double mian = 1.0;
        int i = 0, n = 0;
		
	while(el > prec) {
        n++; 
		el = licz / mian;
		licz *= x;
		mian *= n;
	}

	licz = mian = 1.0;
        while(i < n) {
                sum += licz / mian;
                licz *= (-1) * x * x;
                mian *=  (i + 1) * (i + 2);
                i += 2;
        }
        return sum;
}

void tabCos(double a, double b, double k, double prec) {
        printf("x,              cos(x),         cos_taylor(x)\n");
        while(a<=b) {
                printf("%f,             %f,             %f\n", a, cos(a), cost(a, prec));
                a += k;
        }
}
int main(void) {
        double a, b, k, prec;
        a = 0;
        b = 2 * PI;
        k = PI/6;
        prec = 1e-6;
        printf("Podaj a, b, k(krok), precyzja:\n");
        int unused __attribute__((unused));
        unused = scanf("%lf %lf %lf %lf", &a, &b, &k, &prec);
        tabCos(a, b, k, prec);


        return 0;
}

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846


/*
        ZnajdŸ pole powierzchni ograniczone osi¹ Ox i wykresem funkcji sin(x) w przedziale [a, b] metod¹ Monte Carlo. 
        Dane wejœciowe: a, b, N (liczba losowanych punktów).
*/

// liczy przybli¿on¹ wartoœæ ca³ki ozn. z |sinx|
double pole(int a, int b, int N) {
        if(a>b) return -1;
        int i;
        int k = 0;
        double ppr = b-a;
        double x, y;
        for(i=0; i<N; i++) {
                x = drand48()*(b-a) + a;
                y = drand48();
                if(fabs(sin(x)) >= y) k++;
        }
        printf("k=%d\n", k);
        return (k/(double)N) * ppr;
}

// liczy przybli¿on¹ wartoœæ ca³ki ozn. z sinx
double pole2(int a, int b, int N) {
        if(a>b) return -1;
        int i;
        int k = 0;
        double ppr = 2*(b-a);
        double x, y;
        for(i=0; i<N; i++) {
                x = drand48()*(b-a) + a;
                y = (drand48()*2)-1;
                if(sin(x) >= y && y>0) {
                        k++;
                } else if(sin(x) <= y && y<0) {
                        k--;
                }
        }
        printf("k=%d\n", k);
        return ((k/(double)N) * ppr);
}

int main(void) {
        double a, b;
        int N;
        a = 0;
        b = 2 * PI;
        N = 1e6;
		
        printf("Podaj a, b, N(ilosc punktow):\n");
        int unused __attribute__((unused));
        unused = scanf("%lf %lf %d", &a, &b, &N);
        printf("a=%f, b=%f, N=%d P=%f\n", a, b, N, pole2(a, b, N));

        return 0;
}

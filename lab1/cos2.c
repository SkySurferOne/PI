#include <stdio.h>
#include <math.h>
/*
	Napisaæ program tabelaryzuj¹cy funkcjê cosinus 
	w zadanym przedziale. Dane wejœciowe: 
	pocz¹tek przedzia³u, koniec przedzia³u, krok (przyrost x). 
	Tabela powinna zawieraæ 3 kolumny: 
	wartoœæ argumentu x, wartoœæ cos(x) policzon¹ 
	z wykorzystaniem funkcji bibliotecznej oraz wartoœæ cos(x) 
	policzon¹ z rozwiniêcia w szereg Taylora. 
*/

#define PI 3.14159265

double cost(double x, int n) {
	double sum = 0;
	double licz = 1.0;
	double mian = 1.0;
	int i;
	for(i=0; i<2*n; i+=2) {
		sum += licz / mian;
		licz *= (-1) * x * x;
		mian *= (i+1)*(i+2);
	}
	return sum;
}

void tabCos(double a, double b, double k) {
	printf("x,		cos(x),		cos_taylor(x)\n");
	while(a<b) {
		printf("%f,		%f,		%f\n", a, cos(a), cost(a, 20)); 
		a += k;
	}
}

int main(/*int argc, char * argv[]*/) {
	//if(argc != 3) {printf("Za ma³o argumentów!\n"); return 1;}
	// atol() - converts cstring to number
	tabCos(0, 2*PI, PI/6);
	return 0;
}

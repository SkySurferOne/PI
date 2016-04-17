#include <stdio.h>
#include <math.h>
/*
	Napisa� program tabelaryzuj�cy funkcj� cosinus 
	w zadanym przedziale. Dane wej�ciowe: 
	pocz�tek przedzia�u, koniec przedzia�u, krok (przyrost x). 
	Tabela powinna zawiera� 3 kolumny: 
	warto�� argumentu x, warto�� cos(x) policzon� 
	z wykorzystaniem funkcji bibliotecznej oraz warto�� cos(x) 
	policzon� z rozwini�cia w szereg Taylora. 
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
	//if(argc != 3) {printf("Za ma�o argument�w!\n"); return 1;}
	// atol() - converts cstring to number
	tabCos(0, 2*PI, PI/6);
	return 0;
}

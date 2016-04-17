#include <stdio.h>
#include <stdlib.h>

int upp(int a) {
	return (a+1)/2;
}

void show(int * tab, int n) {
	for(int i=0; i<n; i++) 
		printf("%d ", tab[i]);
	printf("\n");
}

int main(void) {
	int N;
	printf("Podaj N: ");
	scanf("%d", &N);
	int * liczby = (int *) calloc(N, sizeof(int));

	for(int i=0; i<N; i++)
		scanf("%d", liczby+i);
	
	int M = (N+1)/2;
	int * wynik = (int *) calloc(M, sizeof(int));
	for(int i=0; i<N; i+=2) {
		if(i+1 == N) 
		wynik[i/2] = liczby[i];
			else 
		wynik[i/2] = (liczby[i] + liczby[i+1])/2;
	}

	show(liczby, N);
	show(wynik, M);

	return 0;
}
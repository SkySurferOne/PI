#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show(int ** tab, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int getsum(int i, int j, int r, int n, int ** F) {
		int a, b, sum = 0;
		for(a=max(i-r, 0); a<=min(n-1, i+r); a++) {
			for(b=max(j-r, 0); b<=min(n-1, j+r); b++) {
				sum += F[a][b];
			}
		}
	return sum;
}	

void sum(int ** F, int ** W, int r, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			W[i][j] = getsum(i, j, r, n, F);
		}
	}	
}

int main(void) {
	srand(time(NULL));
	int n, r, **F, **W;

	printf("Podaj n i r:\n");
	scanf("%d%d", &n, &r);
	
	printf("Podaj el. mapy:\n");
	F = (int **) calloc(n, sizeof(int*));
	int i, j;
	for(i=0; i<n; i++) {
		F[i] = (int *) calloc(n, sizeof(int));
		for(j=0; j<n; j++) { 
			scanf("%d", &(F[i][j]));
		}
	}  
	show(F, n);

	W = (int **) calloc(n, sizeof(int*));
	for(i=0; i<n; i++) {
		W[i] = (int *) calloc(n, sizeof(int));
		for(j=0; j<n; j++) {	
			W[i][j] = 0;
		}
	}

	sum(F, W, r, n);
	show(W, n);

	
	return 0;
}

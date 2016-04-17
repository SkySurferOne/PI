#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// zakres górny wartości w macierzach
#define RANGE 10

// pokazuje macierz uzupełnioną
void show2(int ** A, int ** B, int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n+1; j++) {
			if(j != n) printf("%d ", A[i][j]);
			else printf("%d", B[i][0]);
		}
		printf("\n");
	}
	printf("\n");
}

void show(int ** M, int a, int b) {
	for(int i=0; i<a; i++) {
		for(int j=0; j<b; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
	printf("\n");
}

int power(int x, int n) {
	if(n == 0) return 1;
	int mult = x;
	for(int i=0; i<n-1; i++)
		mult *= x;
	return mult;
}

void free2D(int ** tab, int n) {
   for(int i=0; i<n;i++)
        free(tab[i]);
    free(tab);
}

int ** genMatrix(int a, int b) {
	srand48(time(NULL));
	int ** M = (int **) calloc(a, sizeof(int *));

	for(int i=0; i<a; i++) {
		M[i] = (int *) calloc(b, sizeof(int));
		for(int j=0; j<b; j++)
			M[i][j] = lrand48()%RANGE;
	}

	return M;
}

int ** getMinor(int ** M, int iM, int jM, int n) {
	int ** minor = (int **) calloc(n-1, sizeof(int *));
	int _im = 0, _jm;

	for(int i=0; i<n; i++) {
		if(i == iM) continue;
		minor[_im] = (int *) calloc(n-1, sizeof(int));
		_jm = 0;
		for(int j=0; j<n; j++) {
			if(j != jM) {
				minor[_im][_jm] = M[i][j];
				_jm++;
			}
		}
		_im++;
	}

	return minor;
}

int calcDet(int ** M, int n) {
	if(n == 1) 
		return M[0][0];
	if(n == 2) 
		return ((M[0][0]*M[1][1])-(M[1][0]*M[0][1]));
	if(n == 3)
		return ((M[0][0]*M[1][1]*M[2][2])
				+(M[1][0]*M[2][1]*M[0][2])
				+(M[2][0]*M[0][1]*M[1][2])
				-(M[2][0]*M[1][1]*M[0][2])
				-(M[0][0]*M[2][1]*M[1][2])
				-(M[1][0]*M[0][1]*M[2][2]));
	// laplace
	int det = 0;
	for(int j=0; j<n; j++) {
		int ** m = getMinor(M, 0, j, n);
		det += M[0][j] * power(-1, j+1) * calcDet(m, n-1);  
		free2D(m, n-1);
	}

	return det;
}

int ** changeCol(int ** A, int ** B, int n, int c) {
	int ** M = (int **) calloc(n, sizeof(int *));
	for(int i=0; i<n; i++) {
		M[i] = (int *) calloc(n, sizeof(int));
		for(int j=0; j<n; j++)
			M[i][j] = A[i][j];
	}

	for(int i=0; i<n; i++)
		M[i][c] = B[i][0];

	return M;
}

int main(void) {
	// Napisać program rozwiązujący układ równań liniowych A*x = B stopnia n. 
	// Dane do programu powinny być podane w następującej postaci: 
	// rząd równania, n, kolejne wiersze macierzy współczynników, A, a następnie kolumna wyrazów wolnych, B.

	int n, ** A, ** B;
	printf("Podaj stopień układu równań: ");
	scanf("%d", &n);

	A = genMatrix(n, n);
	B = genMatrix(n, 1);

	printf("Macierz A: \n");
	show(A, n, n);
	printf("Macierz B: \n");
	show(B, n, 1);
	printf("Macierz A|B: \n");
	show2(A, B, n);

	int detA = calcDet(A, n);

	// oblicz rozwiazania
	int * C = (int *) calloc(n, sizeof(int));
	int zDets = 0;
	for(int i=0; i<n; i++) {
		int ** M = changeCol(A, B, n, i); 
		C[i] = calcDet(M, n);
		free2D(M, n);
		if(C[i] == 0) zDets++;
	}

	if(detA == 0 && zDets == n)
		printf("Układ ma nieskończenie wiele rozwiazań\n");
	else if(detA == 0)
		printf("Układ nie ma rozwiazań\n");
	else {
		printf("Rozwiązania układu:\n");
		for(int i=0; i<n; i++)
			printf("x%d = %f\n",i+1, (double) C[i]/(double) detA);
	}

	free2D(A, n);
	free2D(B, n);
	free(C);

	return 0;
}
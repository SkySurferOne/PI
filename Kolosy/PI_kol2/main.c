#include <stdio.h>
#include <stdlib.h>

//gcc test.c -o test -std=c99 -Wall -lm && ./test

int __getMaxField(int ** field, int n, int _i, int _j) {
	int h = 0, b = 0, maxf = 0;
	for (int i = _i; i < n; i++) {
		if (field[i][_j] == 1) break;
		b = 0; h++;
		for (int j = _j; j < n; j++) {
			if (field[i][j] == 0) {
				b++;
			}
			else {
				int f = h*b;
				if (f > maxf) maxf = f;
				break;
			}
		}
	}
	int f = h*b;
	if (f > maxf) maxf = f;
	return maxf;
}

int getMaxField(int ** field, int n) {
	int maxf = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == 0) {
				int f = __getMaxField(field, n, i, j);
				if (f > maxf) maxf = f;
			}
		}
	}
	return maxf;
}

int main(void) {
	int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);

	// 0 uzytkowy, 1 nieuzytk
	// wypisac najw pow dzialki
	// jesli wsz sa nieuzytk wypisz 0

	int ** dzialka = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i<n; i++) {
		dzialka[i] = (int *)calloc(n, sizeof(int));
		for (int j = 0; j<n; j++) {
			scanf_s("%d", &dzialka[i][j]);
		}
	}

	int max = getMaxField(dzialka, n);
	printf("Wynik: %d\n", max);

	getchar();
	getchar();
	return 0;
}
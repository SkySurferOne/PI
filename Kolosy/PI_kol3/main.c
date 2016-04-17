#include <stdio.h>
#include <stdlib.h>

int sum(int n) {
	int sum = 0, i = 1;
	while (i <= n)
		sum += i++;
	return sum;
}

int * genTab(int n) {
	int * tab = (int *) calloc(n, sizeof(int));
	for  (int i = 0; i < n; ++i)
		tab[i] = i + 1;
	return tab;
}

void gen(int n) {
	int h = 1;
	while (sum(h) < n)
		h++;

	int * tab = genTab(n);
	for (int i = h; i > 0; --i) {
		int j = 0;
		while (1) {
			int ind = sum(i+j-1) + j;
			if (ind >= n) break;
			else printf("%d ", tab[ind]);
			j++;
		}
		printf("\n");
	}

	free(tab);
}

int main() {
	int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);

	gen(n);

	getchar();
	getchar();
	return 0;
}
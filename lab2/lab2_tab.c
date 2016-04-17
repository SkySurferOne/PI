#include <stdio.h>

typedef long long int longInt;

void print(int A[]) {
	for(int i = 0; i < 10000; i++) 
		if(A[i] != -1) printf("%d", A[i]);
	printf("\n");
}

int main(void) {
	longInt A, B;
	//longInt N = 1e4;
	int res[10000];
	int tA [100], tB [100];
  
	scanf("%d", &A);
	scanf("%d", &B);
	//printf("%d\n", A);

	for(int i = 0; i < 100; i++)
		tA[i] = tB[i] = -1;
	
	for(int i = 0; i < 10000; i++) 
		res[i] = -1;

	for(int i = 99; i >= 0 && A > 0; i--) {
			tA[i] = A%10;
			A /= 10; 
	}
	for(int i = 99; i >= 0 && B > 0; i--) {
			tB[i] = B%10;
			B /= 10; 
	}

	//print(tA, tB);
	
	int d = 0; 
	for(int i = 99; i >= 0 && tB[i] != -1; i--) {
		for(int j = 99; j >= 0 && tA[j] != -1; j--) {
			if (res[j - d] == -1) res[j - d] = 0;
			int w = tA[j] * tB[i];
			res[j-d] += w%10;
			if(w/10 > 0 && res[j-d-1] == -1) res[j-d-1] = 0;
			res[j-d-1] += w/10;	
			
		}	
	print(res);
		d++;	
	}
		
	print(res);
	
	return 0;
}

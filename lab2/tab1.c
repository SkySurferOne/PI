#include <stdio.h>

typedef long long int longInt;
int max = 200;
int numlen = 100;

void print(int A[]) {
        for(int i = 0; i < max; i++)
                if(A[i] != -1) printf("%d", A[i]);
        printf("\n");
}

int main(void) {
        longInt A, B;
        int res [max];
        int tA [numlen], tB [numlen];

        scanf("%lld", &A);
        scanf("%lld", &B);

        for(int i = 0; i < max; i++) {
                res[i] = -1;
                if(i < numlen) tA[i] = tB[i] = -1;
        }

        for(int i = numlen-1; i >= 0 && A > 0; i--) {
                        tA[i] = A%10;
                        A /= 10;
        }
        for(int i = numlen-1; i >= 0 && B > 0; i--) {
                        tB[i] = B%10;
                        B /= 10;
        }

        // mnożenie liczb
        int d = -numlen;
        for(int i = numlen-1; i >= 0 && tB[i] != -1; i--) {
                for(int j = numlen-1; j >= 0 && tA[j] != -1; j--) {
                        if (res[j - d] == -1) res[j - d] = 0;
                        res[j-d] += tA[j] * tB[i];
                }
                d++;
        }

        // przerzuca nadmiar do przodu
        for(int i=max-1; i >= 0; i--) {
        	if(res[i] > 9) {
        		if(res[i-1] == -1) res[i-1] = 0;
        		res[i-1] += res[i] / 10;
        		res[i] %= 10;
        	}
        }

        print(res);

        return 0;
}

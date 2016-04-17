#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    double x, y, z, minlen;
};

double sq(double a) {
    return a*a;
}

void genMinlen(struct point * points, int n) {
    double minlen;
    for (int i = 0; i < n; ++i) {
        minlen = INFINITY;
        for (int j = 0; j < n; ++j) {
            if(i != j) {
                double len = sqrt(sq(points[i].x - points[j].x) +
                                  sq(points[i].y - points[j].y) +
                                  sq(points[i].z - points[j].z));
                if(len < minlen) minlen = len;
            } else continue;
        }
        points[i].minlen = minlen;
    }
}

int compare(const void * a, const void * b) {
    struct point _a = *(struct point  *) a;
    struct point _b = *(struct point  *) b;
    if(_a.minlen > _b.minlen) return  1;
    else if(_a.minlen == _b.minlen) return 0;
    else return -1;
}

void show(struct point * points, int n) {
    for (int i = 0; i < n; ++i)
        printf("%lf %lf %lf\n", points[i].x, points[i].y, points[i].z);
    printf("\n");
}

void showMlen(struct point * points, int n) {
    for (int i = 0; i < n; ++i)
        printf("%lf\n", points[i].minlen);
    printf("\n");
}

int main() {
    int n;
    printf("Podaj ilosc punktow: ");
    scanf("%d", &n);
    struct point * points = (struct point *) calloc(n, sizeof(struct point));

    // wczytaj punkty
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &points[i].x);
        scanf("%lf", &points[i].y);
        scanf("%lf", &points[i].z);
    }

    genMinlen(points, n);
    showMlen(points, n);
    // sortuj
    qsort(points, n, sizeof(struct point), compare);
    show(points, n);

    return 0;
}
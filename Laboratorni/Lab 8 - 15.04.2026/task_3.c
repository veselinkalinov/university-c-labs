#include <math.h>
#include <stdio.h>

#define POINT_COUNT 6

struct Point {
    float x;
    float y;
    float z;
};

float findDistance(struct Point a, struct Point b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dz = b.z - a.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main(void) {
    struct Point points[POINT_COUNT];
    int i;

    for (i = 0; i < POINT_COUNT; i++) {
        printf("Tochka %d\n", i + 1);
        printf("x = ");
        scanf("%f", &points[i].x);
        printf("y = ");
        scanf("%f", &points[i].y);
        printf("z = ");
        scanf("%f", &points[i].z);
        printf("\n");
    }

    for (i = 0; i + 2 < POINT_COUNT; i += 3) {
        float sideAB = findDistance(points[i], points[i + 1]);
        float sideBC = findDistance(points[i + 1], points[i + 2]);
        float sideCA = findDistance(points[i + 2], points[i]);

        printf("Triugalnik %d:\n", i / 3 + 1);
        printf("A(%.2f, %.2f, %.2f)\n", points[i].x, points[i].y, points[i].z);
        printf("B(%.2f, %.2f, %.2f)\n", points[i + 1].x, points[i + 1].y, points[i + 1].z);
        printf("C(%.2f, %.2f, %.2f)\n", points[i + 2].x, points[i + 2].y, points[i + 2].z);
        printf("Strana AB = %.2f\n", sideAB);
        printf("Strana BC = %.2f\n", sideBC);
        printf("Strana CA = %.2f\n\n", sideCA);
    }

    return 0;
}

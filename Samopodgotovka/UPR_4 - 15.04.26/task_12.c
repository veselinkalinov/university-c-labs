#include <stdio.h>

int main(void) {
    char *cities[5] = {"Sofia", "Plovdiv", "Varna", "Burgas", "Pleven"};
    int distances[5][5];
    int route[8];
    int count;
    int total = 0;

    printf("Cities:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d -> %s\n", i, cities[i]);
    }

    printf("Enter the 5x5 distance matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &distances[i][j]);
        }
    }

    printf("Enter number of destinations in the route (max 8): ");
    scanf("%d", &count);

    if (count < 2 || count > 8) {
        printf("Invalid route length.\n");
        return 0;
    }

    printf("Enter the route as city numbers:\n");
    for (int i = 0; i < count; i++) {
        scanf("%d", &route[i]);
    }

    for (int i = 0; i < count - 1; i++) {
        total += distances[route[i]][route[i + 1]];
    }

    printf("Route: ");
    for (int i = 0; i < count; i++) {
        printf("%s", cities[route[i]]);
        if (i < count - 1) {
            printf(" -> ");
        }
    }
    printf("\n");

    printf("Total length: %d km\n", total);

    return 0;
}

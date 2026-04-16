#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    int *from, *to;
    int *degree;
    int **friends;
    int *index;
    int q;

    printf("Enter number of people and friendships: ");
    scanf("%d %d", &n, &m);

    from = (int *)malloc(m * sizeof(int));
    to = (int *)malloc(m * sizeof(int));
    degree = (int *)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &from[i], &to[i]);
        degree[from[i]]++;
        degree[to[i]]++;
    }

    friends = (int **)malloc((n + 1) * sizeof(int *));
    index = (int *)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        friends[i] = (int *)malloc(degree[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int a = from[i];
        int b = to[i];

        friends[a][index[a]++] = b;
        friends[b][index[b]++] = a;
    }

    printf("Enter number of queries: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int person;
        scanf("%d", &person);

        printf("Person %d has %d friends:", person, degree[person]);
        for (int j = 0; j < degree[person]; j++) {
            printf(" %d", friends[person][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        free(friends[i]);
    }
    free(friends);
    free(index);
    free(degree);
    free(from);
    free(to);

    return 0;
}

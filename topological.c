
#include <stdio.h>

#define MAX 20

int main() {

    int n, i, j;

    int graph[MAX][MAX];

    int indegree[MAX] = {0};

    int visited[MAX] = {0};

    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);

            /* Calculate indegree */
            if(graph[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("\nTopological Ordering:\n");

    while(count < n) {

        for(i = 0; i < n; i++) {

            /* Select vertex with indegree 0 */
            if(indegree[i] == 0 && visited[i] == 0) {

                printf("%d ", i);

                visited[i] = 1;

                count++;

                /* Reduce indegree of adjacent vertices */
                for(j = 0; j < n; j++) {

                    if(graph[i][j] == 1)
                        indegree[j]--;
                }
            }
        }
    }

    return 0;
}

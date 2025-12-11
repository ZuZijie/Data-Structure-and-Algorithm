#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

int main() {
    int length = 0;
    int *tree;

    while (true) {

        scanf("%d", &length);
        if (!length) break;  

        tree = malloc(length * sizeof(int));

        for (int i = 0; i < length; i++) {
            scanf("%d", &tree[i]);
        }

        int depth;
        scanf("%d", &depth);
        depth--;
        
        int start = (1 << depth) - 1;          
        int end=(1 << (depth + 1)) - 2;     

        if (start >= length) {
            printf("EMPTY\n");
            free(tree);
            continue;
        }

        if (end >= length) end = length - 1;

        for (int j = start; j <= end; j++) {
            if( j == end ) {
                printf("%d", tree[j]);
                break;
            }
            printf("%d ", tree[j]);
        }
        printf("\n");

        free(tree);
    }

    return 0;
}
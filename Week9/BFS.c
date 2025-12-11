#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    int data[50];
    int front; // 队头
    int rear;  // 队尾
} Queue;

void InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

int IsQueueEmpty(Queue *Q) {
    return Q->front == Q->rear;
}

void EnQueue(Queue *Q, int value) {
    Q->data[Q->rear] = value;
    Q->rear = (Q->rear + 1) % 50; 
}

int DeQueue(Queue *Q) {
    int value = Q->data[Q->front];
    Q->front = (Q->front + 1) % 50; 
    return value;
}

void BFS(int n, int *Martrix, int *visited, int startVex) {
    Queue Q;
    InitQueue(&Q);

    
    visited[startVex] = 1;
    printf("%d ", startVex); 
    EnQueue(&Q, startVex);

    while (!IsQueueEmpty(&Q)) {
        int u = DeQueue(&Q); 

        for (int w = 0; w < n; w++) {
            if (Martrix[u * n + w] == 1) { 
                if (visited[w] == 0) {
                    visited[w] = 1;         
                    printf("%d ", w);       
                    EnQueue(&Q, w);         
                }
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *visited = (int*)calloc(n, sizeof(int));
    if (visited == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    

    int Martrix[2501];
    for(int i = 0; i < 2501; i++){
        Martrix[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            scanf("%d", &temp);
            if(temp==1){
                Martrix[i*n + j]=1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            // 如果 i 尚未访问，则从 i 开始进行一次 BFS 遍历
            BFS(n, Martrix, visited, i);
        }
    }
    
    printf("\n"); // 遍历结束
    
    free(visited);
    return 0;
}
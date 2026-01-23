#include <stdio.h>
#include <stdlib.h>

#define MAX 50
//stack for DFS
struct stack{
    int value[MAX];
    int top;
};
//queue for BFS
struct queue{
    int value[MAX];
    int front;
    int rear;
};

//stack operations
void insert_in_stack(struct stack *q,int val){
    if(q->top == MAX -1){
        printf("stack overflow \n");
        return;
    }
    q->top=q->top+1;
    q->value[q->top]= val;
}

void remove_from_stack(struct stack *q){
    if(q->top == -1){
        printf("stack underflow \n");
        return;
    }
    q->top = q->top -1;
}

int peek_stack(struct stack* q){
    if(q->top == -1){
        printf("stack underflow \n");
        return -1;
    }
    return q->value[q->top];
}

void enqueue(struct queue *s,int value){
    if(s->rear == MAX-1){
        printf("queue is full \n");
        return;
    }
    s->rear = s->rear + 1;
    s->value[s->rear] = value;
    if(s->front == -1){
        s->front = 0;
    }
}

//queue operations
void dequeue(struct queue *s){
    if(s->front == -1 || s->front > s->rear){
        printf("queue is empty \n");
        return;
    }
    s->front++;
}

int peek_queue(struct queue *s){
    if(s->front == -1 || s->front > s->rear){
        printf("queue is empty \n");
        return -1;
    }
    return s->value[s->front];
}

// BFS using Queue 
void bfs(int graph[MAX][MAX], int vertices, int start) {
    struct queue q;
    //intializing visited array
    int visited[MAX] = {0};
    int i, v;

    q.front = q.rear = -1;

    enqueue(&q, start);
    visited[start] = 1;

    printf("BFS Order of Traversal: ");
    //loop till queue is not empty
    while (q.front != -1 && q.front <= q.rear) {
        v = peek_queue(&q);
        dequeue(&q);
        printf("%d ", v);

        //visit the neighbour nodes that is unvisited
        for (i = 0; i < vertices; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

//DFS using Stack 
void dfs(int graph[MAX][MAX], int vertices, int start) {
    struct stack s;
    int visited[MAX] = {0};
    int i, v;

    s.top = -1;
    insert_in_stack(&s, start);

    printf("DFS Order of Traversal: ");
    //loop till stack is not empty
    while (s.top != -1) {
        v = peek_stack(&s);
        remove_from_stack(&s);

        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;

            for (i = vertices - 1; i >= 0; i--) {
                if (graph[v][i] == 1 && visited[i] == 0) {
                    insert_in_stack(&s, i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX] = {0};
    int vertices = 5;

    //intializing graph i.e bidirectional
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;

    //implement dfs and bfs from vertex 0
    bfs(graph, vertices, 0);
    dfs(graph, vertices, 0);

    return 0;
}

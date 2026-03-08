#define Q_SIZE 200001
#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
typedef struct node{
    int data;
    struct node *next;
}node;
nodeptr adj[200001];

int q[Q_SIZE];
int front = 0, rear = 0;
void push(int x);
int pop();

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        insert(u, v);
        insert(v, u);
    }
    for(int i = 0; i < k; i++){
        int input;
        scanf("%d", &input);
        push(input);
    }
    int time = 0;
    int v_cnt = n;
    int post_cnt = k;
    while(m >= v_cnt){
        time++; k = 0;
        v_cnt -= post_cnt;
        for(int r = 0; r < post_cnt; r++){
            int u = pop();
            nodeptr ptr = adj[u];
            for(; ptr; ptr = ptr->next){
                int v = ptr->data;
                nodeptr post = NULL, cur = adj[v];
                for(; cur; cur = cur->next){
                    if(cur->data == u){
                        nodeptr tmp = cur;
                        post->next = cur->next;
                        free(tmp);
                        m--;
                    }
                    post = cur;
                }
                push(v);
                k++;
            }
        }
        post_cnt = k;
    }
    printf("%d", time);

    for(int i = 0; i< n+1; i++)
        free(adj[i]);
    free(adj);

    return 0;
}
nodeptr create_node(int data){
    nodeptr node = (nodeptr)malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    return node;
}
void insert(int u, int v){          //인접 리스트 생성(정점번호순 정렬)
    nodeptr node = create_node(v);
    nodeptr p = adj[u];
    if(p == NULL)
        adj[u] = node;
    else{
        while(p->next != NULL && p->next->data < v)
            p = p->next;
        node->next = p->next;
        p->next = node;
    }
}
void push(int x){
    front = (front + 1) % Q_SIZE;
    q[front] = x;
}
int pop(){
    rear = (rear + 1) % Q_SIZE;
    return q[rear];
}
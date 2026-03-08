#define MAX_QUEUE_SIZE 1000000
#include <stdio.h>

typedef struct {
    int r;
    int c;
}place;
place queue[MAX_QUEUE_SIZE];
int front, rear;

void addq(place item);
place deleteq();

int cross_walk[1002][1002];
int stream[1002][1002];

int rr[] = {0, 1, 0, -1};
int cc[] = {1, 0, -1, 0};

void find_stream(int i, int j);

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int h, w;
    scanf("%d %d", &h, &w);

    for(int i = 1; i < n+1; i++)
        cross_walk[i][0] = cross_walk[i][m+1] = -1;
    for(int j = 1; j < m+1; j++)
        cross_walk[0][j] = cross_walk[n+1][j] = -1;

    for(int i = 1; i < n+1; i++)
        for(int j = 1; j < m+1; j++)
            scanf("%d", &cross_walk[i][j]);
    
    place tmp;
    int k, r, c;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &r, &c);
        stream[r][c] = 1;
        find_stream(r, c);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 2; j <= m; j++)
            stream[i][j] += stream[i][j-1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= m; j++)
            stream[i][j] += stream[i-1][j];

    int cnt = 0;
    for(int i = h; i <= n; i++){
        for(int j = w; j <= m; j++){
            if((stream[i-h][j-w] - stream[i-h][j]) - (stream[i][j-w] - stream[i][j]) == h*w)
                cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
void addq(place item){
    rear = (rear+1)%MAX_QUEUE_SIZE;
    queue[rear] = item;
}
place deleteq(){
    front = (front+1)%MAX_QUEUE_SIZE;
    return queue[front];
}
void find_stream(int i, int j){
    place cur = {i, j};
    addq(cur);
    int r, c, n_r, n_c;
    while(front != rear){
        cur = deleteq();
        r = cur.r; c = cur.c;
        for(int i = 0; i < 4; i++){
            n_r = r+rr[i];
            n_c = c+cc[i];

            if(!stream[n_r][n_c] && cross_walk[n_r][n_c] >= cross_walk[r][c]){
                stream[n_r][n_c] = 1;
                cur.r = n_r; cur.c = n_c;
                addq(cur);
            }
        }
    }
}
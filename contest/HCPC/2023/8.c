// #define Q_SIZE 2500
// #include <stdio.h>

// typedef struct{
//     int x, y;
// }Point;
// Point q[Q_SIZE];
// int front = 0, rear = 0;

// void addq(Point);
// Point deleteq();

// int visited[50];
// int sdoku[50][50];
// int ans[50][50];

// int rr[4] = {0, 1, 0, -1};
// int cc[4] = {1, 0, -1, 0};

// void bfs(int i, int j);
// int n, cnt = 1;
// int main(){
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             scanf("%d", &sdoku[i][j]);
    
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             if(ans[i][j] == 0)              
//                 bfs(i, j);
    
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++)
//             printf("%d ", ans[i][j]);
//         printf("\n");
//     }
//     return 0;
// }
// void addq(Point item){
//     rear = (rear + 1) % Q_SIZE;
//     q[rear] = item;
// }
// Point deleteq(){
//     front = (front + 1) % Q_SIZE;
//     return q[front];
// }
// void bfs(int i, int j){
//     Point cur = {i, j};
//     addq(cur);
//     int visited[50] = {0};
//     visited[sdoku[i][j]] = 1;
//     int r, c, n_r, n_c;
//     while(front != rear){
//         cur = deleteq();
//         r = cur.x; c = cur.y;
//         for(int k = 0; k < 4; k++){
//             n_r = r + rr[k];
//             n_c = c + cc[k];
//             if(0 <= n_r && n_r < n && 0 <= n_c && n_c < n){
//                 if(!visited[sdoku[n_r][n_c]] && ans[n_r][n_c] == 0){
//                     Point next = {n_r, n_c};
//                     addq(next);
//                     visited[sdoku[n_r][n_c]] = 1;
//                 }
//             }
//         }
//         ans[r][c] = cnt;
//     }
//     cnt++;
// }
#include <stdio.h>

int sdk[50][50];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &sdk[i][j]);
        }
    }

    int cnt = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", cnt);
        }
        printf("\n");
        cnt++;
    }
}
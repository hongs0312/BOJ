#include <stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int creat[1001][2];
    for(int i = 1; i <= n; i++){
        creat[i][0] = -1;
        creat[i][1] = -1; 
    }
    int a, c; char b;
    for(int i = 0; i < m; i++){
        scanf("%d %c %d", &a, &b, &c);

        if(b == 'P') //광합성
            creat[a][0] = c;
        else         //운동성
            creat[a][1] = c;
    }

    int max = 0, min = 0;
    for(int i = 1; i <= n; i++){
        if(creat[i][0] == 1){
            if(creat[i][1] == 0){
                max++; min++;
            }
            else if(creat[i][1] == -1){
                max++;
            }
        }
        else if(creat[i][0] == -1){
            if(creat[i][1] == 0 || creat[i][1] == -1)
                max++;
        }
    }
    printf("%d %d", min, max);


    return 0;
}
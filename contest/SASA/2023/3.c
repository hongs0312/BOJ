#define K 100
#include <stdio.h>

char rsp[K+1];

int main(){
    for(int i = 0; i < K; i++)
        rsp[i] = '2';
    
    int post_wincnt, cur_wincnt;
    scanf("%d", &post_wincnt);

    for(int i = 0; i < K; i++){
        rsp[i] = '0';
        printf("? %s\n", rsp);
        fflush(stdout);

        scanf("%d", &cur_wincnt);
        if(cur_wincnt == K){
            break;
        }

        if(cur_wincnt < post_wincnt){
            rsp[i] = '2';
        }
        else if(cur_wincnt == post_wincnt){
            rsp[i] = '5';
            post_wincnt++;
        }
        else post_wincnt++;

    }
    for(int i = 0; i < K; i++){
        switch (rsp[i]){
        case '0':
            rsp[i] = '2';
            break;
        case '2':
            rsp[i] = '5';
            break;
        case '5':
            rsp[i] = '0';
            break;
        }
    }
    printf("! %s\n", rsp);
    fflush(stdout);

    return 0;
}
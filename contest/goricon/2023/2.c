#include <stdio.h>

int main(){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    if((b/10)%2 == 1 && b/10 != 5){
        int cnt = 2;
        printf("%d", a);
        if(a%10 == 9){
            printf("7");
            cnt++;
        }
        for(int i = cnt; i < n-2; i++){
            printf("1");
        }
        printf("%d", b);
    }
    else{
        printf("-1");
    }

    return 0;
}
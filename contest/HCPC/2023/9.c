#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int x, y;
    scanf("%d %d", &x, &y);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(y > b){
            x = a; y = b;
        }
    }
    printf("%d %d", x, y);
    return 0;
}
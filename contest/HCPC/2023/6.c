#define ABS(x) ((x) > 0 ? (x) : -(x))
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int x = 0, p, c;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &p, &c);
        if(ABS(p - x) <=  c)
            x++;
    }
    printf("%d", x);

    return 0;
}
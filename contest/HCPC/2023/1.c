#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int input;
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        for(int i = 0; i < input/5; i++)
            printf("++++ ");
        for(int i = 0; i < input%5; i++)
            printf("|");
        printf("\n");
    }
    
    return 0;
}
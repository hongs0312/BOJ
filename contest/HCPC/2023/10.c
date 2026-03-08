#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char a[1000001], b[1000001];
        scanf("%s %s", a, b);
        int len_a = strlen(a), len_b = strlen(b);

        for(int j = 0; j < len_a; j++){
            if(a[j] == 'x' || a[j] == 'X') {
                if(islower(b[j]))
                    printf("%c", toupper(b[j]));
                else
                    printf("%c", b[j]);
                break;
            }
        }
    }
    return 0;
}
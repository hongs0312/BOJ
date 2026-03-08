#include <stdio.h>
#include <stdlib.h>

int s[200000];
int cmp(const void *a, const void *b);
int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    
    qsort(s, n, sizeof(int), cmp);

    printf("%d", s[n-1] + n - 1);
    
    return 0;
}
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
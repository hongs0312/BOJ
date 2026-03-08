#include <stdio.h>

long long int arr[200001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    
    int q, c, l, r;
    long long int k;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d %d %d", &c, &l, &r);
        if(c == 1){
            scanf("%lld" , &k);
            int cnt = 0;
            for(int j = l; j <= r; j++)
                if(arr[j] == k)
                    cnt++;
            printf("%d\n", cnt);
        }
        else{
            for(int j = l; j <= r; j++)
                arr[j] = 0;
        }
    }
    return 0;
}
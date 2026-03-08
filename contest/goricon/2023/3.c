#define COMPARE(x, y) (((x) < (y))? -1: ((x) == (y))? 0: 1)
#define MAX(a, b) (((a) > (b))? (a) : (b))
#include <stdio.h>

long long int logs[500001][2];
int top = 0;

int binsearch(int search_num, int left, int right);

int main(){
    int n;
    scanf("%d", &n);

    int a, b, cnt = 0;
    long long int max;
    for(int q = 0; q < n; q++){
        scanf("%d %d", &a, &b);

        if(a == 1){
            logs[++top][0] = b;
            logs[top][1] = ++cnt;
            max = b;
        }
        else{
            int t = MAX(max-b, 0);
            int idx = binsearch(t, 1, top);
            
            logs[idx][0] = t;
            logs[idx][1] = cnt;
            top = idx; max = t;
        }
    }
    long long int sum = 0;
    for(int i = 1; i <= top; i++)
        sum += logs[i][0]*(logs[i][1]-logs[i-1][1]);

    printf("%lld", sum);

    return 0;
}
int binsearch(int search_num, int left, int right){
    int middle;
    while(left < right){
        middle = (left+right)/2;
        switch (COMPARE(logs[middle][0], search_num)){
        case -1: 
            left = middle+1;
            break;
        case 0: return middle;
        case 1: 
            right = middle;
            break;
        }
    }
    return right;
}
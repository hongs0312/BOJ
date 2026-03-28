/*
9184
신나는 함수 실행
*/
#include <bits/stdc++.h>

#define MAX 21

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef vector<int> v_int;
typedef vector<v_int> m_int;

vector<m_int> dp(MAX, m_int(MAX, v_int(MAX, -1)));

int w(int a, int b, int c);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int a, b, c;
    while(true) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}
int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;

    if(a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if(dp[a][b][c] == -1){
        if(a < b && b < c)
            dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        else
            dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return dp[a][b][c];
}
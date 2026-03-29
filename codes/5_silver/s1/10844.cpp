/*
10844
쉬운 계단 수
*/
#include <bits/stdc++.h>

#define DIGIT 10
#define MOD 1000000000

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef vector<int> v_int;
vector<v_int> dp; // dp[n][m] == n으로 시작하는 길이가 m인 계단수의 개수

int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    dp.assign(DIGIT, v_int(n+1));
    for(int i = 0; i < DIGIT; i++)
        dp[i][1] = 1;

    for(int j = 2; j <= n; j++) {
        for(int i = 0; i < DIGIT; i++) {
            if(i-1 >= 0)
                dp[i][j] = (dp[i-1][j-1] + dp[i][j]) % MOD;

            if(i+1 < DIGIT)
                dp[i][j] = (dp[i+1][j-1] + dp[i][j]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i < DIGIT; i++)
        ans = (dp[i][n] + ans) % MOD;

    cout << ans;

    return 0;
}
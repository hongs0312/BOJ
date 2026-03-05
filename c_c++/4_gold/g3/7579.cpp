/*
7579
앱
*/
#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef vector<int> v_int;
typedef vector<v_int> m_int;

v_int apps, cost;
m_int dp;

int knap_sack(int idx, int w);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, m;
    cin >> n >> m;

    apps.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> apps[i];

    cost.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> cost[i];

    int result = 0x7fffffff;
    dp.assign(n+1, v_int(MAX));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < MAX; j++) {
            if(j < cost[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-cost[i]]+apps[i], dp[i-1][j]);

            if(dp[i][j] >= m)
                result = min(j, result);
        }
    }
    cout << result;

    return 0;
}
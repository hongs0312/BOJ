/*
2673
교차하지 않는 원의 현들의 최대집합
*/
#include <bits/stdc++.h>

#define MAX 101

using namespace std;

typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int dp(MAX, v_int(MAX)), c(MAX, v_int(MAX, 0));

int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;

        c[u][v] = c[v][u] = 1;
    }

    for(int i = 1; i < MAX; i++) {
        for(int j = i; j >= 1; j--) {
            for(int k = j; k < i; k++) {
                dp[j][i] = max(dp[j][k]+dp[k][i]+c[i][j], dp[j][i]);
            }
        }
    }
    cout << dp[1][100];

    return 0;
}
/*
1328
고층 빌딩
*/
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<v_ll> m_ll;
typedef vector<m_ll> t_ll;

t_ll dp;

ll get_dp(int n, int cur);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n, r, l;
    cin >> n >> l >> r;

    dp.assign(n+1, m_ll(n+1, v_ll(n+1, 0)));

    dp[1][1][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k]*(i-2) + dp[i][j][k])%MOD;
            }   
        }
    }
    cout << dp[n][l][r];

    return 0;
}
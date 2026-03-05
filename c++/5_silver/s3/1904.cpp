/*
1904
01타일
*/
#include <bits/stdc++.h>

#define MOD 15746

using namespace std;

vector<int> dp;

int n;
int get_dp(int idx);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    cin >> n;

    dp.assign(n, -1);

    cout << get_dp(0);

    return 0;
}
int get_dp(int idx){
    if(idx >= n)  {
        if(idx == n) 
            return 1;
        return 0;
    }

    if(dp[idx] != -1) return dp[idx];

    dp[idx] = 0;

    dp[idx] += get_dp(idx + 1);
    dp[idx] += get_dp(idx + 2);

    dp[idx] %= MOD;

    return dp[idx];
}
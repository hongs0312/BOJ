/*
9465
스티커
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp; //dp[i][j] == v[i][j]의 스티커를 뗏을 때 얻을 수 있는 최대 점수

int main() {
    // freopen("../../IO_files/in.txt", "r", stdin);
    // freopen("../../IO_files/out.txt", "w", stdout);
    
    int r;
    cin >> r;
    while(r-- > 0) {
        int n;
        cin >> n;

        //get input
        v.clear();
        v.assign(2, vector<int>(n+1));
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> v[i][j+1];

        //get result using DP
        dp.clear();
        dp.assign(2, vector<int>(n+1, 0));

        dp[0][1] = v[0][1];
        dp[1][1] = v[1][1];

        for(int i = 2; i <= n; i++) {
            dp[0][i] = v[0][i] + max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2]));
            dp[1][i] = v[1][i] + max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2]));
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }

    return 0;
}
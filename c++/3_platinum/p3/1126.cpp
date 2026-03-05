/*
1126
같은 탑
*/
#include <bits/stdc++.h>

#define MAX 500001

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<int>> dp; //dp[i][j] == i번째 블럭까지 확인 했을 때 높이차가 j인 두 탑 중 높은 탑의 높이

int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;
    
    dp.assign(n+1, vector<int>(MAX, -1));
    dp[0][0] = 0;

    int a, b, h;
    for(int i = 1; i <= n; i++) {
        cin >> h;
        for(int diff = 0; diff < MAX; diff++) {
            if(dp[i-1][diff] == -1) continue;

            a = dp[i-1][diff];
            b = a - diff;

            //둘 다 두지 않는 경우
            dp[i][diff] = max(a, dp[i][diff]);

            //a에 두는 경우
            dp[i][diff + h] = max(a + h, dp[i][diff + h]);
            
            //b에 두는 경우
            if(diff >= h) //차이보다 블럭이 작으므로
                dp[i][diff - h] = max(a, dp[i][diff - h]);
            else
                dp[i][h - diff] = max(b + h, dp[i][h - diff]);
        }
    }
    cout << ((dp[n][0] > 0)?dp[n][0]:-1);

    return 0;
}
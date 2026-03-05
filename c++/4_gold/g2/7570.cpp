/*
7570
줄 세우기
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
vector<int> dp;
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;

    dp.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
        dp[i] = -1;

    int cur;
    for(int i = 0; i < n; i++) {
        cin >> cur;

        if(cur-1 > 0 && dp[cur-1] != -1) {
            dp[cur] = dp[cur-1]+1;
        }
        else {
            dp[cur] = 0;
        }
    }
    int dp_max = *max_element(dp.begin(), dp.end());
    int result = n-dp_max-1;

    cout << result;

    return 0;
}
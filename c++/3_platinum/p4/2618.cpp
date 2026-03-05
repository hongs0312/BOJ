/*
2618
경찰차
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> place;

vector<place> incedent;
vector<vector<int>> dp;  // dp[i][j] = 1번 경찰차가 i번 사건을, 2번 경찰차가 j번 사건을 마지막으로 처리한 이후 사건처리를 끝낼 수 있는 최소 이동거리
vector<vector<int>> trace; // dp[i][j] 에서 어떠 경찰차가 사건을 처리 했는지 기록

int w;

int solve(int a, int b);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;

    incedent.push_back({1, 1});
    incedent.push_back({n, n});

    cin >> w;

    dp.assign(w+2, vector<int>(w+2, -1));
    trace.assign(w+2, vector<int>(w+2));

    for(int i = 0; i < w; i++) {
        int r, c;
        cin >> r >> c;

        incedent.push_back({r, c});
    }
    cout << solve(0, 1) << "\n";

    int a = 0, b = 1;
    for(int i = 2; i < w+2; i++) {
        cout << trace[a][b] << "\n";
        if(trace[a][b] == 1)
            a = i;
        else
            b = i;
    }

    return 0;
}

int getDistance(int n, int m) {
    place a = incedent[n], b = incedent[m];

    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int n, int m) {
    int next = max(n, m) + 1;

    if(next >= w+2) return 0;

    if(dp[n][m] != -1) 
        return dp[n][m];

    int calc1 = solve(next, m) + getDistance(n, next); // if solve the incedent police car 1
    int calc2 = solve(n, next) + getDistance(m, next); // if solve the incedent police car 2

    if(calc1 < calc2) {
        dp[n][m] = calc1;
        trace[n][m]= 1;
    }
    else {
        dp[n][m] = calc2;
        trace[n][m] = 2;
    }
    return dp[n][m];
}
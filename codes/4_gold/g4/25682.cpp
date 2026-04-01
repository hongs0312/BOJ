/*
25682
체스판 다시 칠하기 2
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<int>> board_sum; // 검은 색이 왼쪽 상단 일때 색을 반전해야하는 횟수 누적합

char get_correct(int i, int j);
int get_sum(int r, int c, int k);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    int n, m, k;
    cin >> n >> m >> k;

    board_sum.assign(n+1, vector<int> (m+1, 0));

    string s;
    bool b;
    for(int i = 0; i < n; i++) {
        cin >> s;

        for(int j = 0; j < m; j++) {
            board_sum[i+1][j+1] = board_sum[i][j+1] + board_sum[i+1][j] - board_sum[i][j];

            // 원래 색과 다른 경우
            if(get_correct(i, j) != s[j])
                board_sum[i+1][j+1] += 1;
        }
    }

    int tmp, b_size = k*k, ans = b_size;
    for(int i = 0; i <= n-k; i++) {
        for(int j = 0; j <= m-k; j++) {
            tmp =  get_sum(i, j, k);

            ans = min(tmp, ans);
            ans = min(b_size - tmp, ans);
        }
    }
    cout << ans;

    return 0;
}
char get_correct(int i, int j) {
    // 행, 열이 둘 다 홀수 or 둘 다 짝수 일때 => 원래 검은색
    if(((i%2 == 0) && (j%2 == 0)) || ((i%2 == 1) && (j%2 == 1)))
        return 'B';
    else
        return 'W';
}
int get_sum(int r, int c, int k) {
    int ret = 0;

    ret += board_sum[r][c] + board_sum[r+k][c+k];
    ret -= board_sum[r][c+k] + board_sum[r+k][c];

    return ret;
}
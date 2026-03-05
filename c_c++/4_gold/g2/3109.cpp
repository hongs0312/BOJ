/*
3109
빵집
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p_int;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

v_int rr = {-1, 0, 1};
v_int cc = {1, 1, 1};
m_int pipe_map;

int n, m;

bool dfs(int n, int r, int c);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    pipe_map.assign(n, v_int(m));

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.')
                pipe_map[i][j] = 0;
            else
                pipe_map[i][j] = -1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(pipe_map[i][0] != 0)
            continue;

        if(dfs(i+1, i, 0) == true)
            ans += 1;
    }
    cout << ans;

    return 0;
}
bool dfs(int num, int r, int c) {
    pipe_map[r][c] = num;

    //reach the end
    if(c == m-1) return true;

    int n_r, n_c;
    for(int i = 0; i < 3; i++) {
        n_r = r + rr[i];
        n_c = c + cc[i];

        //handling out of range
        if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
            continue;

        //if there is some obstacle
        if(pipe_map[n_r][n_c] != 0)
            continue;

        if(dfs(num, n_r, n_c) == true)
            return true;
    }
    return false;
}
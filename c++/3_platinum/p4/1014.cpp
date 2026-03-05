/*
1014
컨닝
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int seat, adj;
v_int visited, matched;

void get_adj(int n, int m, int even_cnt);
int bipartite_matching(int n);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int c;
    cin >> c;

    int n, m, odd_cnt, even_cnt;
    while(c-- > 0) {
        cin >> n >> m;

        seat.assign(n, v_int(m, 0));
        
        even_cnt = odd_cnt = 0;

        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(int j = 0; j < m; j++) {
                if(s[j] == '.') {
                    if(j%2 == 0)
                        seat[i][j] = ++even_cnt;
                    else
                        seat[i][j] = ++odd_cnt;
                }
                else
                    seat[i][j] = 0;
            }
        }
        get_adj(n, m, even_cnt);

        matched.assign(odd_cnt+1, 0);

        int tmp = bipartite_matching(even_cnt);
        cout << even_cnt + odd_cnt - tmp << "\n";

    }
    
    return 0;
}
void get_adj(int n, int m, int even_cnt) {
    int n_r, n_c;
    
    v_int rr = {-1, -1, 0, 0, 1, 1};
    v_int cc = {-1, 1, -1, 1, -1, 1};

    int v, n_v;
    adj.assign(even_cnt+1, v_int(0));
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(c%2 == 0 && seat[r][c] != 0) {
                for(int i = 0; i < 6; i++) {
                    n_r = r + rr[i];
                    n_c = c + cc[i];

                    if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                        continue;

                    if(seat[n_r][n_c] == 0)
                        continue;
                    
                    v = seat[r][c];
                    n_v = seat[n_r][n_c];

                    adj[v].push_back(n_v);
                }
            }
        }
    }
}
bool dfs(int cur) {
    visited[cur] = 1;

    for(int next:adj[cur]) {
        if(visited[matched[next]] == 1) continue;

        if(matched[next] == 0 || dfs(matched[next])) {
            matched[next] = cur;

            return true;
        }
    }

    return false;
}
int bipartite_matching(int n) {
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        visited.assign(n+1, 0);
    
        if(dfs(i) == true) ans++;
    }
    return ans;
}
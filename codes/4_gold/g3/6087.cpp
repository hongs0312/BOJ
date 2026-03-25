/*
6087
레이저 통신
*/
#include <bits/stdc++.h>

#define INF 0x7fffffff

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
typedef pair<int, int> p_int;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

v_int rr = {1, -1, 0, 0};
v_int cc = {0, 0, 1, -1};

m_int raser_map;

int bfs(int n, int m, p_int depart, p_int dest);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    fast_io();

    int n, m;
    cin >> m >> n;

    raser_map.assign(n, v_int(m, 0));

    vector<p_int> ends;

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '*')
                raser_map[i][j] = -1;
            else if(s[j] == 'C')
                ends.push_back({i, j});
        }
    }
    cout << bfs(n, m, ends[0], ends[1]);

    return 0;
}
int bfs(int n, int m, p_int cur, p_int dest) {
    deque<pair<p_int, p_int>> dq;
    pair<p_int, p_int> tmp;

    m_int visited(n, v_int(m, 0));
    m_int cost(n, v_int(m, INF));

    int r, c, n_r, n_c, mirrors, n_mirrors, post_dir;
    
    r = cur.first; c = cur.second;
    visited[r][c] = 1;

    dq.push_back({{-1, -1}, cur});
    while(dq.size() > 0) {
        tmp = dq.front(); dq.pop_front();

        mirrors = tmp.first.first;
        post_dir = tmp.first.second;

        cur = tmp.second;
        r = cur.first; c = cur.second;

        for(int i = 0; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                continue;

            if(post_dir == i)   n_mirrors = mirrors;
            else                n_mirrors = mirrors+1;

            if(raser_map[n_r][n_c] == -1 || cost[n_r][n_c] < n_mirrors || visited[n_r][n_c] >= 3)
                continue;

            if(post_dir == i)
                dq.push_front({{n_mirrors, i}, {n_r, n_c}});
            else
                dq.push_back({{n_mirrors, i}, {n_r, n_c}});

            cost[n_r][n_c] = n_mirrors;
            visited[n_r][n_c]++;
        }
    }
    r = dest.first; c = dest.second;

    return cost[r][c];
}
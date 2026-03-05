/*
4991
로봇 청소기
*/
#include <bits/stdc++.h>

#define INF 0x3fffffff
#define SPACE 0
#define WALL -1
#define DIRTY -2

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

vector<p_int> points;
m_int room, adj, node_num, dp;

void input(int n, int m);
void bfs(int n, int m, p_int start);
int tsp(int n, int cur, int visited);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    fast_io();
    
    int n, m, ans;
    while(true) {
        cin >> m >> n;

        if(n == 0 && m == 0)
            break;

        input(n, m);
        
        int cnt = points.size();
        adj.assign(cnt, v_int(cnt, INF));
        dp.assign(cnt, v_int((1 << cnt)-1, INF));

        for(int i = 0; i < cnt; i++)
            bfs(n, m, points[i]);
        
        ans = tsp(cnt, 0, 1);
        if(ans == INF) ans = -1;

        cout << ans << "\n";
    }
    return 0;
}
void input(int n, int m) {
    string s;
    int dirty_cnt = 0;

    points.clear();
    room.assign(n, v_int(m, 0));
    node_num.assign(n, v_int(m, -1));
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'x')
                room[i][j] = WALL;
            else if(s[j] == '*') {
                room[i][j] = DIRTY;

                dirty_cnt++;

                points.push_back({i, j});
                node_num[i][j] = dirty_cnt;
            }
            else if(s[j] == 'o') {
                points.insert(points.begin(), {i, j});
                node_num[i][j] = 0;
            }
        }
    }
}
void bfs(int n, int m, p_int start) {
    queue<p_int> q;
    p_int cur = start;

    m_int visited(n, v_int(m, -1));

    int r, c, n_r, n_c;
    r = cur.first; c = cur.second;
    visited[r][c] = 0;

    int u, v;
    u = node_num[r][c];

    q.push(cur);
    while(q.size() > 0) {
        cur = q.front(); q.pop();

        r = cur.first; c = cur.second;
        if(room[r][c] == DIRTY) {
            v = node_num[r][c];

            adj[u][v] = visited[r][c];
        }

        for(int i = 0; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                continue;

            if(room[n_r][n_c] == WALL || visited[n_r][n_c] != -1)
                continue;

            q.push({n_r, n_c});
            visited[n_r][n_c] = visited[r][c]+1;
        }
    }
}
int tsp(int n, int cur, int visited) {
    if(visited == (1 << n)-1)
        return 0;

    if(dp[cur][visited] != INF)
        return dp[cur][visited];

    int tmp;
    for(int i = 0; i < n; i++) {
        if((visited & (1 << i)) != 0)
            continue;

        tmp = tsp(n, i, visited+(1 << i)) + adj[cur][i];

        dp[cur][visited] = min(tmp, dp[cur][visited]);
    }
    return dp[cur][visited];
}
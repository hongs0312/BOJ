/*
2933
미네랄
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p_int;
typedef vector<p_int> v_p_int;

typedef vector<int> v_int;
typedef vector<v_int> m_int;

v_int rr = {1, -1, 0, 0};
v_int cc = {0, 0, 1, -1};

m_int cave;
v_p_int throw_boom(int n, int m, int r, int dir);
v_p_int get_cluster(int n, int m, p_int p);
void drop(int n, int m, v_p_int &v);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    cave.assign(r, v_int(c, 0));

    string s;
    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            if(s[j] == 'x')
                cave[i][j] = -1;
        }
    }
    int n, input, dir;
    cin >> n;

    m_int visited;
    v_p_int start, cluster;
    for(int i = 0; i < n; i++) {
        cin >> input;

        if((i&1) == 0)  dir = 1;
        else            dir = -1;

        start = throw_boom(r, c, r-input, dir);
        for(p_int p:start) {
            cluster = get_cluster(r, c, p);

            if(cluster.size() == 0)
                continue;

            drop(r, c, cluster);
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << ((cave[i][j]==0)?'.':'x');

        cout << '\n';
    }
    return 0;
}
v_p_int throw_boom(int n, int m, int r, int dir) {
    v_p_int ret;

    int c = (dir>0)?0:m-1; //dir == 1 -> start at left, dir == -1 -> start at right
    int n_r, n_c;
    while(true) {
        if(c < 0 || c >= m)
            break;

        if(cave[r][c] == -1) {
            cave[r][c] = 0;
            
            for(int i = 0; i < 4; i++) {
                n_r = r + rr[i];
                n_c = c + cc[i];

                if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                    continue;

                if(cave[n_r][n_c] == -1)
                    ret.push_back({n_r, n_c});
            }
            break;
        }
        c += dir;
    }
    return ret;
}
v_p_int get_cluster(int n, int m, p_int p) {
    m_int visited(n, v_int(m, 0));
    v_p_int cluster;

    queue<p_int> q;
    p_int tmp;

    int r, c, n_r, n_c;
    r = p.first; c = p.second;
    if(cave[r][c] == 0)
        return cluster;

    visited[r][c] = 1;

    q.push(p);
    while(q.size() > 0) {
        tmp = q.front(); q.pop();

        r = tmp.first;
        c = tmp.second;

        for(int i = 0; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                continue;

            if(cave[n_r][n_c] == 0 || visited[n_r][n_c] == 1)
                continue;

            q.push({n_r, n_c});
            visited[n_r][n_c] = 1;
        }
        cluster.push_back({r, c});
    }
    return cluster;
}
void get_down(int n, int m, v_p_int &v) {
    int r, c;
    while(true) {
        for(int i = 0; i < v.size(); i++) {
            r = v[i].first;
            c = v[i].second;

            if(r+1 >= n || cave[r+1][c] == -1)
                return;
        }
        for(int i = 0; i < v.size(); i++) {
            r = v[i].first;
            c = v[i].second;

            v[i] = {r+1, c};
        }
    }
}
void drop(int n, int m, v_p_int &v) {
    int r, c;
    for(p_int p:v) {
        r = p.first; c = p.second;

        cave[r][c] = 0;
    }
    get_down(n, m, v);
    for(p_int p:v) {
        r = p.first; c = p.second;

        cave[r][c] = -1;
    }
}
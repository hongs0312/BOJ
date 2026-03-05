/*
9376
탈옥
*/
#include <bits/stdc++.h>

#define WALL -1
#define GATE -2
#define SPACE 0

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
typedef pair<int, int> p_int;
typedef pair<int, p_int> elem;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

v_int rr = {1, -1, 0, 0};
v_int cc = {0, 0, 1, -1};

vector<p_int> prisonors;
m_int jail, gate_cnt;

void bfs(int h, int w, p_int p);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    fast_io();

    int r;
    cin >> r;

    int h, w, ans;
    string s;
    while(r-- > 0) {
        cin >> h >> w;

        jail.assign(h+2, v_int(w+2, 0));
        gate_cnt.assign(h+2, v_int(w+2, -1));
        prisonors.clear();

        for(int i = 0; i < h; i++) {
            cin >> s;
            for(int j = 0; j < w; j++) {
                if(s[j] == '*')
                    jail[i+1][j+1] = WALL;
                else if(s[j] == '#')
                    jail[i+1][j+1] = GATE;
                else if(s[j] == '$')
                    prisonors.push_back({i+1, j+1});
            }
        }
        h += 2; w += 2;
        bfs(h, w, {0, 0});
        bfs(h, w, prisonors[0]);
        bfs(h, w, prisonors[1]);

        int ans = 0x7fffffff;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(gate_cnt[i][j] < 0)
                    continue;

                if(jail[i][j] == GATE)
                    gate_cnt[i][j] -= 2;

                ans = min(gate_cnt[i][j], ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
void bfs(int h, int w, p_int p) {
    deque<elem> dq;
    m_int visited(h, v_int(w, 0));
    
    int r, c, n_r, n_c, opend;
    
    r = p.first; c = p.second;
    visited[r][c] = 1;
    
    dq.push_front({0, p});

    elem tmp;
    while(dq.size() > 0) {
        tmp = dq.front(); dq.pop_front();

        opend = tmp.first;
        p = tmp.second;

        r = p.first; c = p.second;
        if(gate_cnt[r][c] == -1)
            gate_cnt[r][c] = 0;
        
        gate_cnt[r][c] += opend;

        for(int i = 0; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            if(n_r < 0 || n_r >= h || n_c < 0 || n_c >= w)
                continue;

            if(jail[n_r][n_c] == WALL || visited[n_r][n_c] == 1)
                continue;

            if(jail[n_r][n_c] == GATE)
                dq.push_back({opend+1, {n_r, n_c}});
            else
                dq.push_front({opend, {n_r, n_c}});

            visited[n_r][n_c] = 1;
        }
    }
}
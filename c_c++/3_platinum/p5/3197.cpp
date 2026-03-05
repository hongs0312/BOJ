/*
3197
백조의 호수
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p_int;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

v_int parent, rank_set, swans;
v_int rr = {1, -1, 0, 0};
v_int cc = {0, 0, 1, -1};
m_int lake, swan_visit;

queue<p_int> cur_swan, next_swan, cur_water, next_water;

void init_set(int n);
int find_set(int x);
void union_set(int a, int b);

void swan_bfs(int n, int m);
void melt_ice(int n, int m);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s;
    lake.assign(n, v_int(m, 0));
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'X')
                lake[i][j] = -1;
            else {
                cur_water.push({i, j});

                if(s[j] == 'L') {
                    swans.push_back(m*i + j);

                    cur_swan.push({i, j});
                }
            }
        }
    }
    init_set(n*m);
    swan_visit.assign(n, v_int(m, 0));

    int ans = 0;
    while(true) {
        swan_bfs(n, m);
        
        if(find_set(swans[0]) == find_set(swans[1]))
            break;

        melt_ice(n, m);
        ans++;
    }
    cout << ans;

    return 0;
}
void init_set(int n) {
    rank_set.assign(n, 1);
    parent.resize(n);

    for(int i = 0; i < n; i++)
        parent[i] = i;
}
int find_set(int x) {
    //부모가 자기자신이면 자신이 root
    if(parent[x] == x)
        return x;

    //경로 압축
    parent[x] = find_set(parent[x]);

    return parent[x];
}
void union_set(int a, int b) {
    //a와 b의 루트 구하기
    a = find_set(a);
    b = find_set(b);

    //부모가 같으면 return
    if(a == b) return;

    //rank가 더 큰 set이 a에 오게 swap
    if(rank_set[a] < rank_set[b])
        swap(a, b);

    //b를 a아래에 병합
    parent[b] = a;

    if(rank_set[a] == rank_set[b])
        rank_set[a] += 1;
}
void swan_bfs(int n, int m) {
    p_int tmp;
    int r, c, n_r, n_c, cur, next;
    while(cur_swan.size() > 0) {
        tmp = cur_swan.front(); cur_swan.pop();

        r = tmp.first;
        c = tmp.second;

        cur = m*r + c;
        for(int i = 0 ; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                continue;

            next = m*n_r + n_c;
            if(find_set(cur) == find_set(next))
                continue;

            if(lake[n_r][n_c] == 0){
                union_set(cur, next);

                cur_swan.push({n_r, n_c});
            }
            else if(lake[n_r][n_c] == -1 && swan_visit[n_r][n_c] == 0) {
                next_swan.push({n_r, n_c});

                swan_visit[n_r][n_c] = 1;
            }
        }
    }
    cur_swan = next_swan;
    next_swan = queue<p_int>();
}
void melt_ice(int n, int m) {
    p_int tmp;
    int r, c, n_r, n_c;
    while(cur_water.size() > 0) {
        tmp = cur_water.front(); cur_water.pop();

        r = tmp.first;
        c = tmp.second;

        for(int i = 0 ; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m)
                continue;

            if(lake[n_r][n_c] == -1) {
                next_water.push({n_r, n_c});

                lake[n_r][n_c] = 0;
            }
        }
    }
    cur_water = next_water;
    next_water = queue<p_int>();
}
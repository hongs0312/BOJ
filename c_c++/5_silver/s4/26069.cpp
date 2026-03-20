/*
26069
붙임성 좋은 총총이
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef vector<int> v_int;

v_int parent, rank_set;
map<string, int> m;

void init_set(int n);
int find_set(int x);
void union_set(int a, int b);

int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    int n;
    cin >> n;

    init_set(2*n);

    m.insert({"ChongChong", 0});
    
    string a, b;
    int u, v, p_u, p_v, p_0;
    int cc = -1, cnt = 1, ans = 1;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;

        auto it_a = m.find(a);
        if(it_a != m.end())
            u = it_a->second;
        else
            u = m.insert({a, cnt++}).first->second;

        auto it_b = m.find(b);
        if(it_b != m.end())
            v = it_b->second;
        else
            v = m.insert({b, cnt++}).first->second;
        
        p_u = find_set(u); p_v = find_set(v);
        if(p_u != p_v) {
            p_0 = find_set(0);
            if(p_u == p_0 || p_v == p_0) {
                union_set(u, v);
                ans++;
            }
        }
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
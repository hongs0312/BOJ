/*
2887
행성 터널
*/
#include <bits/stdc++.h>

#define INF 0x7fffffff

using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<v_ll> m_ll;

m_ll planets;
priority_queue<v_ll> pq;
v_ll parent, rank_set;

bool x_cmp(v_ll &v1, v_ll &v2){
    return v1[0] < v2[0];
}
bool y_cmp(v_ll &v1, v_ll &v2){
    return v1[1] < v2[1];
}
bool z_cmp(v_ll &v1, v_ll &v2){
    return v1[2] < v2[2];
}
void init_set(int n);
ll kruskal(int n);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    init_set(n);
    
    int x, y, z;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;

        planets.push_back({x, y, z, i});
    }

    cout << kruskal(n);

    return 0;
}
ll get_cost(v_ll &a, v_ll &b) {
    ll ret = INF;

    for(int i = 0; i < 3; i++) 
        ret = min(abs(a[i]-b[i]), ret);

    return ret;
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
void get_edge(int n) {
    ll cost;
    sort(planets.begin(), planets.end(), x_cmp);
    for(int i = 0; i < n-1; i++) {
        cost = get_cost(planets[i], planets[i+1]);

        pq.push({-cost, planets[i][3], planets[i+1][3]});     
    }

    sort(planets.begin(), planets.end(), y_cmp);
    for(int i = 0; i < n-1; i++) {
        cost = get_cost(planets[i], planets[i+1]);

        pq.push({-cost, planets[i][3], planets[i+1][3]});   
    }

    sort(planets.begin(), planets.end(), z_cmp);
    for(int i = 0; i < n-1; i++) {
        cost = get_cost(planets[i], planets[i+1]);

        pq.push({-cost, planets[i][3], planets[i+1][3]});
    }
}
ll kruskal(int n) {
    get_edge(n);

    v_ll tmp;
    ll a, b, min_cost, total = 0;
    
    int i = 0;
    while(i < n-1) {
        if(pq.size() == 0)  break;

        tmp = pq.top(); pq.pop();

        min_cost = -tmp[0];
        a = tmp[1];
        b = tmp[2];

        if(find_set(a) == find_set(b))
            continue;

        union_set(a, b);
        total += min_cost;

        i++;
    }
    return total;
}
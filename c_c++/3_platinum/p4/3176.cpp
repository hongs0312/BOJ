/*
3176
도로 네트워크
*/
#include <bits/stdc++.h>

#define MAX 40000

using namespace std;

typedef long long ll;
typedef struct elem{
    int vertex;
    ll dist;
}elem;
typedef struct ret {
    int node;
    int min_d, max_d;
}ret;


int max_k;

vector<vector<elem>> adj;
vector<vector<int>> parent;
vector<vector<pair<int, int>>> min_max_dist;
vector<int> level;

void prepare(int n);
ret get_ans(int u, int v);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    adj.resize(n+1);
    level.resize(n+1);

    parent.assign(n+1, vector<int>(16));
    min_max_dist.assign(n+1, vector<pair<int,int>>(16));

    int u, v, d;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v >> d;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    prepare(n);

    ret ans;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        
        ans = get_ans(u, v);
        cout << ans.min_d << " " << ans.max_d << "\n";
    }

    return 0;
}
//arg p: parent node, n: current node, d: distance between parent and cur node, l: level
void get_parent(int p, int n, int d, int l) {
    min_max_dist[n][0] = {d, d};
    parent[n][0] = p;
    level[n] = l;

    for(elem v:adj[n]) {
        if(v.vertex == p) continue;
        get_parent(n, v.vertex, v.dist, l+1);
    }
}
void prepare(int n) {
    get_parent(0, 1, 0, 0);

    int max_level = *max_element(level.begin(), level.end());

    while(max_level > 1) {
        max_level = max_level >> 1;
        max_k++;
    }
    for(int k = 1; k <= max_k; k++) {
        for(int i = 1; i <= n; i++) {
            if(parent[parent[i][k-1]][k-1] != 0) {
                parent[i][k] = parent[parent[i][k-1]][k-1];
                
                min_max_dist[i][k].first = min(min_max_dist[i][k-1].first, min_max_dist[parent[i][k-1]][k-1].first);
                min_max_dist[i][k].second = max(min_max_dist[i][k-1].second, min_max_dist[parent[i][k-1]][k-1].second);
            }
        }
    }
}
ret get_n_th_node(int node, int n) {
    ret result = {0, 0x7fffffff, 0};

    int k = 0;
    while(n > 0) {
        if((n & 1) == 1) {
            result.min_d = min(result.min_d, min_max_dist[node][k].first);
            result.max_d = max(result.max_d, min_max_dist[node][k].second);

            node = parent[node][k];
        }
        n = n >> 1;
        k++;
    }
    result.node = node;

    return result;
}
ret get_ans(int u, int v) {
    int level_u = level[u];
    int level_v = level[v];

    ret tmp, result = {0, 0x7fffffff, 0};
    if(level_u > level_v) {
        int diff = level_u - level_v;
        tmp = get_n_th_node(u, diff);

        u = tmp.node;

        result.min_d = min(result.min_d, tmp.min_d);
        result.max_d = max(result.max_d, tmp.max_d);
    }
    else if(level_u < level_v) {
        int diff = level_v - level_u;
        tmp = get_n_th_node(v, diff);

        v = tmp.node;

        result.min_d = min(result.min_d, tmp.min_d);
        result.max_d = max(result.max_d, tmp.max_d);
    }

    int k;
    while(u != v) {
        k = max_k;
        while(parent[u][k] == parent[v][k] && k > 0) {
            k--;
        }

        result.min_d = min(result.min_d, min(min_max_dist[u][k].first, min_max_dist[v][k].first));
        result.max_d = max(result.max_d, max(min_max_dist[u][k].second, min_max_dist[v][k].second));

        u = parent[u][k];
        v = parent[v][k];
    }

    return result;
}
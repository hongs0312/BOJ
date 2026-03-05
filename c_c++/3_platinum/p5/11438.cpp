/*
11438
LCA 2
*/
#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

vector<vector<int>> adj;
int parent[MAX][17];
vector<int> level;

int max_level;
int max_k; //2^k <-- max of this value
void get_parent(int p, int n, int l);
void prepare(int n);
int get_n_th_parent(int node, int n);
int get_lca(int u, int v);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); //when doing input and output alternativly, it must need line.
    
    int n;
    cin >> n;

    adj.resize(n+1);
    level.resize(n+1);

    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_parent(0, 1, 0);    
    max_level = *max_element(level.begin(), level.end());
    
    int temp = max_level;
    while(temp > 1) {
        temp = temp >> 1;
        max_k++;
    }

    prepare(n);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;

        cout << get_lca(u, v) << "\n";
    }
    return 0;
}
//get parent with dfs algorithm
void get_parent(int p, int n, int l) { //arg : parent num, node num, level
    parent[n][0] = p;
    level[n] = l;
    for(int cur:adj[n]) {
        if (cur == p) continue; //if current node is same to parent node, pass it
        get_parent(n, cur, l+1);
    }
}
//prepare parent[n][k] == 2^(k)th parent of number n node
void prepare(int n) {
    for(int k = 1; k <= max_k; k++) {
        for(int i = 1; i <= n; i++) {
            //parent[parent[i][k-1]][k-1] means num i node's 2^(k-1)th parent's 2^(k-1)th parent : i's 2^(k)th parent
            //if parent[parent[i][k-1]][k-1] == 0 -> it is out of range
            if(parent[parent[i][k-1]][k-1] != 0){
                parent[i][k] = parent[parent[i][k-1]][k-1];
            }
        }
    }
}
//getting LCA by tracing back each nodes parent
int get_lca(int u, int v) { //arg : vertex u, vertex v
    int u_level = level[u];
    int v_level = level[v];

    // //if u and v have different level, equal it
    if(u_level > v_level) {
        int diff = u_level - v_level;
        
        u = get_n_th_parent(u, diff);
        u_level = level[u];
    }
    else if(u_level < v_level) {
        int diff = v_level - u_level;
        
        v = get_n_th_parent(v, diff);
        v_level = level[v];
    }

    while(u != v) {
        int k = max_k;
        
        while(parent[u][k] == parent[v][k] && k > 0) {
            k--;
        }

        u = parent[u][k];
        v = parent[v][k];
    }

    return u;
}

int get_n_th_parent(int node, int n) {
    int k = 0;

    while(n > 0) {
        if(n & 1 == 1) {
            node = parent[node][k];
        }
        n = n >> 1;
        k++;
    }

    return node;
}
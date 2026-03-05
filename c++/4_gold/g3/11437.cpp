/*
11437
LCA
*/
#include <bits/stdc++.h>

#define MAX 50001

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> level;

void get_parent(int p, int n, int l);
int get_lca(int u, int v);
int main() {
    freopen("IO_files/in.txt", "r", stdin);
    freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    adj.resize(n+1);
    parent.resize(n+1);
    level.resize(n+1);

    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_parent(0, 1, 0); 
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;

        cout << get_lca(u, v) << endl;
    }

    return 0;
}
//getting parent with dfs algorithm
void get_parent(int p, int n, int l) { //arg : parent num, node num, level
    parent[n] = p;
    level[n] = l;
    for(int cur:adj[n]) {
        if (cur == p) continue; //if current node is same to parent node, pass it
        get_parent(n, cur, l+1);
    }
}
//getting LCA by tracing back each nodes parent
int get_lca(int u, int v) { //arg : vertex u, vertex v
    int u_level = level[u];
    int v_level = level[v];

    //if u and v have different level, equal it
    while(u_level != v_level) {
        if(u_level > v_level) {
            u = parent[u];
            u_level--;
        }
        else if(u_level < v_level) {
            v = parent[v];
            v_level--;
        }
    }

    //trace back to each parent until meet same parent
    while(u != v) {
        u = parent[u];
        v = parent[v];
    }

    //u == v means they are LCA so return one of them
    return u;
} 
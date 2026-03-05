/*
11725
트리의 부모 찾기
*/
#include <bits/stdc++.h>

#define MAX 100001

using namespace std;


vector<vector<int>> adj;
int parents[MAX];

void get_parent(int parent, int cur);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;

    adj.resize(n+1);
    
    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    get_parent(0, 1);

    for(int i = 2; i <= n; i++)
        cout << parents[i] << "\n";
    
    return 0;
}

void get_parent(int parent, int cur) {
    parents[cur] = parent;
    for(int next:adj[cur]) {
        if(next == parent) continue;

        get_parent(cur, next);
    }
}
/*
2533
사회망 서비스(SNS)
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int dp[1000001][2];

void dfs(int node, int parent);
int main() {
    freopen("IO_files/in.txt", "r", stdin);
    freopen("IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;
    adj.resize(n+1);
    
    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << min(dp[1][0], dp[1][1]);

    return 0;
}

void dfs(int node, int parent) {
    dp[node][0] = 0; // not selected
    dp[node][1] = 1; // selected

    for(int next:adj[node]) {
        if(next == parent) continue; //if the node is parent, passing it

        dfs(next, node);

        dp[node][0] += dp[next][1];
        dp[node][1] += min(dp[next][1], dp[next][0]);
    }
}

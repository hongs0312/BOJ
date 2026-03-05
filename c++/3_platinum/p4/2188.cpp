/*
2188
축사 배정
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int adj;
v_int matched, visited;

int bipartite_matching(int n);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    matched.assign(m+1, 0);
    
    int k, s;
    for(int i = 1; i <= n; i++) {
        cin >> k;

        for(int j = 0; j < k; j++) {
            cin >> s;

            adj[i].push_back(s);
        }
    }
    cout << bipartite_matching(n);

    return 0;
}
bool dfs(int cur) {
    visited[cur] = 1;

    for(int next:adj[cur]) {
        if(visited[matched[next]] == 1) continue;

        if(matched[next] == 0 || dfs(matched[next])) {
            matched[next] = cur;

            return true;
        }
    }

    return false;
}
int bipartite_matching(int n) {
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        visited.assign(n+1, 0);
        
        if(dfs(i) == true) ans++;
    }
    return ans;
}
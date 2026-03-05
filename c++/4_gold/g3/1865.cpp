/*
1865
웜홀
*/
#include <bits/stdc++.h>
#define INF 0x0fffffff

using namespace std;

typedef struct edge {
    int dest;
    int time;
}edge;

vector<vector<edge>> adj;

bool bellman_ford(int n, int s);
int main() {
    // freopen("../../IO_files/in.txt", "r", stdin);
    // freopen("../../IO_files/out.txt", "w", stdout);
    
    int r;
    cin >> r;
    while(r-- > 0) {
        adj.clear();

        int n, m, w;
        cin >> n >> m >> w;
        
        adj.resize(n+1);
        

        int u, v, t;
        //get edges (no directions)
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> t;
            
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        vector<int> wormhole_start;
        //get wormholes (has directions)
        for(int i = 0; i < w; i++) {
            cin >> u >> v >> t;

            adj[u].push_back({v, -t});
            wormhole_start.push_back(u);
        }

        bool has_neg_loop = false;
        for(int i = 0; i < wormhole_start.size(); i++) {
            has_neg_loop |= bellman_ford(n, wormhole_start[i]);
        }
        if(has_neg_loop == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
bool bellman_ford(int n, int s) {
    vector<int> dist;
    dist.assign(n+1, INF);

    dist[s] = 0;

    //refresh dist table
    int dest, time;
    for(int r = 0; r < n-1; r++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                dest = adj[i][j].dest;
                time = adj[i][j].time;
                
                if(dist[i]+time < dist[dest])
                    dist[dest] = dist[i]+time;
            }
        }
    }

    //check neg cycle
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            dest = adj[i][j].dest;
            time = adj[i][j].time;
            
            if(dist[i]+time < dist[dest])
                return true;
        }
    }
    return false;
}
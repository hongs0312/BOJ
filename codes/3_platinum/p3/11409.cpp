/*
11409
열혈강호 6
*/
#include <bits/stdc++.h>

#define INF 0x7fffffff

using namespace std;

typedef pair<int, int> p_int;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int adj, capa, flow, cost;
v_int trace, dist;

void add_edge(int u, int v, int cap, int cst);
p_int mcmf(int n, int s, int t);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    int n, m;
    cin >> n >> m;
    
    capa.assign(n+m+2, v_int(n+m+2));
    flow.assign(n+m+2, v_int(n+m+2));
    cost.assign(n+m+2, v_int(n+m+2));

    adj.resize(n+m+2);

    int cnt, work, cost;
    for(int i = 1; i <= n; i++) {
        //source -> personel
        add_edge(0, i, 1, 0);

        //personel -> work
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> work >> cost;

            add_edge(i, n+work, 1, cost);
        }
    }
    //work -> sink
    for(int i = n+1; i <= n+m; i++)
        add_edge(i, n+m+1, 1, 0);
    
    p_int ans = mcmf(n+m+2, 0, n+m+1);

    cout << ans.first << "\n" << -ans.second;

    return 0;
}
void add_edge(int u, int v, int cap, int cst) {
    adj[u].push_back(v);
    adj[v].push_back(u);

    capa[u][v] = cap;
    
    cost[u][v] = -cst;
    cost[v][u] = cst;
}
bool spfa(int n, int s, int t) {
    trace.assign(n, -1);
    dist.assign(n, INF);

    vector<bool> is_in_q(n, false);

    queue<int> q;
    q.push(s);

    is_in_q[s] = true;
    dist[s] = 0;

    int cur;
    while(q.size() > 0) {
        cur = q.front(); q.pop();
        is_in_q[cur] = false;

        for(int next:adj[cur]) {
            if(capa[cur][next] > flow[cur][next] && dist[next] > dist[cur]+cost[cur][next]) {
                dist[next] = dist[cur] + cost[cur][next];
                trace[next] = cur;

                if(is_in_q[next] == false) {
                    q.push(next);
                    is_in_q[next] = true;
                }
            }
        }
    }
    if(trace[t] == -1) return false;    //there is no route for source -> sink
    else return true;                   //there is route for source -> sink
}
p_int make_flow(int s, int t) {
    int post, cur = t, f = INF;
    
    //find min flow
    while(cur != s) {
        post = trace[cur];

        f = min(capa[post][cur]-flow[post][cur], f);

        cur = post;
    }

    //update flow
    p_int result = {f, 0};
    cur = t;
    while(cur != s) {
        post = trace[cur];

        result.second += cost[post][cur];

        flow[post][cur] += f;
        flow[cur][post] -= f;

        cur = post;
    }

    return result;
}
p_int mcmf(int n, int s, int t) {
    p_int result, ans = {0, 0};

    while(spfa(n, s, t) == true) {
        result = make_flow(s, t);

        if(result.first == 0) break;

        ans.first += result.first;
        ans.second += result.second;
    }
    return ans;
}
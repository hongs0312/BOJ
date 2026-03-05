/*
2316
도시 왕복하기 2
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int adj, capa, flow;
v_int trace;

int edmonds_karp(int n, int s, int t);
int main() {
    freopen("../../0_IO_files/in.txt", "r", stdin);
    freopen("../../0_IO_files/out.txt", "w", stdout);
    
    int n, p;
    cin >> n >> p;

    capa.assign(n+1, v_int(n+1));
    flow.assign(n+1, v_int(n+1));

    adj.resize(n+1);

    int u, v;
    for(int i = 0; i < p; i++) {
        cin >> u >> v;

        adj[u].push_back(v);

        capa[u][v] = 1;
    }
    cout << edmonds_karp(n, 1, 2);

    return 0;
}
bool bfs(int n, int s, int t) {
    trace.assign(n+1, -1);
    
    queue<int> q;
    q.push(s);

    int cur;
    while(q.size() > 0) {
        cur = q.front();
        for(int next:adj[cur]) {
            if(capa[cur][next] > flow[cur][next] && trace[next] < 0) {
                trace[next] = cur;

                q.push(next);

                if(next == t) 
                    return true;
            }
        }
        q.pop();
    }
    return false;
}
int make_flow(int s, int t) {
    int post, cur = t, f = 0x7fffffff;

    while(cur != s) {
        post = trace[cur];

        f = min(capa[post][cur]-flow[post][cur], f);

        cur = post;
    }
    
    cur = t;
    while(cur != s) {
        post = trace[cur];

        flow[post][cur] += f;
        flow[cur][post] -= f;

        cur = post;
    }

    return f;
}
int edmonds_karp(int n, int s, int t) {
    int c, max_flow = 0;

    while(bfs(n, s, t) == true) {
        c = make_flow(s, t);

        if(c == 0) break;

        max_flow += c;
    }
    return max_flow;
}
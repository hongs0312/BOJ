/*
11375
열혈강호
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int adj, capa, flow;
v_int trace;

void add_edge(int u, int v, int c);
int edmonds_karp(int n, int s, int t);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    capa.assign(n+m+2, v_int(n+m+2));
    flow.assign(n+m+2, v_int(n+m+2));

    adj.resize(n+m+2);

    int cnt, w;
    for(int i = 1; i <= n; i++) {
        //source -> personel
        add_edge(0, i, 1);

        //personel -> work
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> w;

            add_edge(i, n+w, 1);
        }
    }
    //work -> sink
    for(int i = n+1; i <= n+m; i++)
        add_edge(i, n+m+1, 1);

    cout << edmonds_karp(n+m+2, 0, n+m+1);

    return 0;
}
void add_edge(int u, int v, int c) {
    adj[u].push_back(v);
    adj[v].push_back(u);

    capa[u][v] = c;
}
bool bfs(int n, int s, int t) {
    trace.assign(n, -1);
    
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
    int post, cur = t, f = 10;

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
/*
6086
최대 유량
*/
#include <bits/stdc++.h>

#define MAX 52

using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<v_ll> m_ll;

m_ll capacity, flow, adj;
v_ll trace;

ll c_to_i(char c);
ll edmonds_karp(ll s, ll t);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);

    capacity.assign(MAX, v_ll(MAX, 0));
    flow.assign(MAX, v_ll(MAX, 0));
    adj.resize(MAX);

    ll n;
    cin >> n;

    char a, b;
    ll c, u, v;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        u = c_to_i(a);
        v = c_to_i(b);

        capacity[u][v] += c;
        capacity[v][u] += c;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << edmonds_karp(0, 25);

    return 0;
}
ll c_to_i(char c) {
    if(isupper(c) != 0)
        return c-'A';
    else
        return c-'a'+26;
}
bool bfs(ll s, ll t) {
    trace.assign(MAX, -1);

    queue<ll> q;
    q.push(s);

    ll cur;
    while(q.size() > 0) {
        cur = q.front();
        q.pop();

        for(ll e:adj[cur]) {
            if(capacity[cur][e] > flow[cur][e] && trace[e] < 0) {
                trace[e] = cur;

                q.push(e);

                if(e == t) return true;
            }
        }
    }
    return false;
}
ll make_flow(ll s, ll t) {
    ll p, cur = t, f = 0x7fffffff;
    while(cur != s) {
        p = trace[cur];
        
        f = min(capacity[p][cur] - flow[p][cur], f);
        
        cur = p;
    }

    cur = t;
    while(cur != s) {
        p = trace[cur];

        flow[p][cur] += f;
        flow[cur][p] -= f;

        cur = p;
    }

    return f;
}
ll edmonds_karp(ll s, ll t) { // s == source, t == sink
    ll c, max_flow = 0;

    while(true) {
        if (bfs(s, t) == false)
            break;

        c = make_flow(s, t);

        max_flow += c;

        if(c == 0) break;
    }

    return max_flow;
}
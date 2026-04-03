/*
13305
주유소
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<long long> dist, cost;
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    
    int n;
    cin >> n;

    n--;

    dist.resize(n);
    for(int i = 0; i < n; i++)
        cin >> dist[i];

    cost.resize(n);
    for(int i = 0; i < n; i++)
        cin >> cost[i];

    long long ans = 0, m = 0x7fffffff;
    for(int i = 0; i < n; i++) {
        m = min(cost[i], m);

        ans += m*dist[i];
    }
    cout << ans;

    return 0;
}
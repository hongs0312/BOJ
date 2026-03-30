/*
2559
수열
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> acum;
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, k;
    cin >> n >> k;

    acum.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> acum[i];
        
        acum[i] += acum[i-1];
    }
    
    int max_num = -0x7fffffff;
    for(int i = 0; i <= n-k; i++)
        max_num = max(acum[i+k]-acum[i], max_num);
    
    cout << max_num;

    return 0;
}
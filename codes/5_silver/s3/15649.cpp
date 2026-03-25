/*
15649
N과 M (1)
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> num, selected;

void solve(int n, int m, int d, int u);
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, m;
    cin >> n >> m;

    num.resize(n);
    for(int i = 0; i < n; i++)
        num[i] = i + 1;

    selected.resize(m);
    solve(n, m, 0, 0);

    return 0;
}
void solve(int n, int m, int d, int u) {
    if(d == m) {
        for(int i = 0; i < m; i++)
            cout << selected[i] << " ";
        
        cout << "\n";
        
        return;
    }
    
    int mask = 1;
    for(int i = 0; i < n; i++) {
        if((u&mask) == 0) {
            selected[d] = num[i];

            solve(n, m, d+1, u+mask);
        }
        mask = mask << 1;
    }
}
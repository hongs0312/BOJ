/*
15651
N과 M (3)
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<int> nums, selected;

void solve(int n, int m, int d); 
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, m;
    cin >> n >> m;

    nums.resize(n);
    for(int i = 0; i < n; i++)
        nums[i] = i+1;

    selected.resize(m);
    solve(n, m, 0);
    
    return 0;
}
void solve(int n, int m, int d) {
    if(d == m) {
        for(int i = 0; i < m; i++)
            cout << selected[i] << " ";

        cout << "\n";
        
        return;
    }
    
    for(int i = 0; i < n; i++) {
        selected[d] = nums[i];

        solve(n, m, d+1);
    }
}
/*
10986
나머지 합
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<long long> last;
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, m;
    cin >> n >> m;

    last.assign(m, 0);
    last[0] = 1;
    
    int input, tmp = 0;    
    for(int i = 0; i < n; i++) {
        cin >> input;
        
        tmp = (tmp + input)%m;

        last[tmp] += 1;
    }
    long long ans = 0;
    for(int i = 0; i < m; i++)
        ans += last[i]*(last[i]-1)/2;
    
    cout << ans;

    return 0;
}
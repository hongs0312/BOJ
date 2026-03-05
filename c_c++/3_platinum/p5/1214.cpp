/*
1214
쿨한 물건 구매
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int d, p, q;
    cin >> d >> p >> q;

    if(p < q) swap(p, q);

    int m = 0x7fffffff;
    for(int n = 0; n < min(d/p, q)+1; n++)
        m = min((q-(d-n*p)%q)%q, m);
    m = min((p-d%p)%p, m);
    
    cout << d+m;

    return 0;
}
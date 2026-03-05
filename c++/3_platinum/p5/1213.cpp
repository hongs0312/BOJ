/*
1213
쿨한 물건 구매
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int get_diff(int d, int p, int q);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int d, p, q;
    cin >> d >> p >> q;

    cout << d-get_diff(d, p, q);

    return 0;
}
int get_diff(int d, int p, int q) {
    if(d < 0) return d;

    int m = -0x7fffffff;
    m = max(get_diff(d-p, p, q), m);
    m = max(get_diff(d-q, p, q), m);

    return m;
}
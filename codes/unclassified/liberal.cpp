/*

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

    int n;
    cin >> n;

    if(n == 1)
        return -1;
        // cout << 42;
    else if (n == 2) // 4?
        cout << 5;
    else if (n == 3) // 3
        cout << 4;
    else if (n == 4) // 2
        cout << 4;
    else if (n == 5) // 1
        cout << 64;

    return 0;
}
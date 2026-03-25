/*
31403
A+B-C
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("IO_files/in.txt", "r", stdin);
    freopen("IO_files/out.txt", "w", stdout);
    
    int a, b, c;
    cin >> a >> b >> c;

    cout << a+b-c << "\n";

    int d = 1;
    while (b >= d) {
        d *= 10;
    }
    
    cout << a*d+b-c;

    return 0;
}
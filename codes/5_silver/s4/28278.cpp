/*
28278
스택 2
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

stack<int> s;
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    int c, x;
    while(n-- > 0) {
        cin >> c;
        if(c == 1) {
            cin >> x;

            s.push(x);
        }
        else if(c == 2) {
            if(s.size() == 0)
                cout << -1 << "\n";
            else {
                cout << s.top() << "\n";

                s.pop();
            }
        }
        else if(c == 3)
            cout << s.size() << "\n";
        else if(c == 4) {
            if(s.size() == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(c == 5) {
            if(s.size() == 0)
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
    }
    return 0;
}
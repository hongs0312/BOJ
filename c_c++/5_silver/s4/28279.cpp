/*
28279
덱 2
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

deque<int> dq;
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a;

        if(a == 1) {
            cin >> b;
            dq.push_front(b);
        }
        else if(a == 2) {
            cin >> b;
            dq.push_back(b);
        }
        else if(a == 3) {
            if(dq.size() == 0)
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(a == 4) {
            if(dq.size() == 0)
                cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(a == 5)
            cout << dq.size() << "\n";
        else if(a == 6) {
            if(dq.size() == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(a == 7) {
            if(dq.size() == 0)
                cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        }
        else if(a == 8) {
            if(dq.size() == 0)
                cout << -1 << "\n";
            else
                cout << dq.back() << "\n";
        }
    }

    return 0;
}
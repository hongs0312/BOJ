/*
18258
큐 2
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
queue<int> q;
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    int num;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;

        if(s == "push") {
            cin >> num;
            q.push(num);
        }
        else if(s == "pop") {
            if(q.size() == 0)
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s == "size")
            cout << q.size() << "\n";
        else if(s == "empty") {
            if(q.size() == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(s == "front") {
            if(q.size() == 0)
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if(s == "back") {
            if(q.size() == 0)
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}
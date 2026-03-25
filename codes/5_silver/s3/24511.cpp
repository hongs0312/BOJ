/*
24511
queuestack
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

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int input;
    for(int i = 0; i < n; i++){
        cin >> input;

        if(v[i] == 0)
            dq.push_front(input);
    }

    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> input;

        dq.push_back(input);

        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}
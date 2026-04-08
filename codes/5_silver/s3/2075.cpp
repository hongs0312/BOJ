/*
2075
N번째 큰 수
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<stack<int>> ss;
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    
    int n;
    cin >> n;

    int input;
    ss.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input;

            ss[j].push(input);
        }
    }

    int m, ans;
    for(int i = 0; i < n; i++) {
        m = 0;
        for(int j = 0; j < n; j++) {
            if(ss[j].size() == 0) continue;

            if(ss[j].top() > ss[m].top())
                m = j;
        }
        ans = ss[m].top();
        ss[m].pop();
    }
    cout << ans;

    return 0;
}
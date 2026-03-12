/*
2346
풍선 터뜨리기
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v;
deque<int> dq;
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    
    int n;
    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];

        dq.push_back(i);
    }
    
    int idx;
    for(int i = 1; i < n; i++) {
        idx = dq.front();
        dq.pop_front();

        cout << idx+1 << " ";
        if(v[idx] >= 0) {
            for(int j = 1; j < v[idx]; j++) {
                dq.push_back(dq.front());

                dq.pop_front();
            }
        }
        else {
            for(int j = 0; j < -v[idx]; j++) {
                dq.push_front(dq.back());

                dq.pop_back();
            }
        }    
    }
    cout << dq.front() + 1;

    return 0;
}
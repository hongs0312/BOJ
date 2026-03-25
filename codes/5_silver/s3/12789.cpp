/*
12789
도키도키 간식드리미
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

    int input, cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> input;

        while(s.size() > 0 && s.top() < input) {
            if(s.top() == cnt + 1)
                cnt ++;

            s.pop();
        }
        s.push(input);
    }

    if(cnt+s.size() == n)
        cout << "Nice";
    else
        cout << "Sad";

    return 0;
}
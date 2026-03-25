/*
5525
IOIOI
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> store;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int n_count = 0;
    for(int i = 0; i < m-2; i++) {
        if(s.substr(i, 3) == "IOI") {
            n_count++;
            i++;
        }
        else {
            store.push_back(n_count);
            n_count = 0;
        }
    }
    store.push_back(n_count);

    int ans = 0, tmp;
    for(int i = 0; i < store.size(); i++) {
        tmp = store[i]-n;
        
        if(tmp >= 0) {
            ans += tmp+1;
        }
    }

    cout << ans;
    
    return 0;
}
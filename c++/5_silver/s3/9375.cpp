/*
9375
패션왕 신해빈
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int r;
    cin >> r;

    int n;
    string a, b;
    while(r-- > 0) {
        m.clear();

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            
            auto iter = m.find(b);
            if(iter == m.end()) {
                m.insert({b, 1});
            }
            else {
                (iter->second)++;
            }
        }

        int ans = 1;
        for(auto element:m) {
            ans *= element.second + 1;
        }
        cout << ans-1 << "\n";
    }

    return 0;
}
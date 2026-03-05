/*
1966
프린터 큐
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool find_more_important(vector<pair<int, int>> v, pair<int, int> p);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int r;
    cin >> r;

    int n, m, t, ans;
    pair<int, int> p;
    while(r-- > 0) {
        cin >> n >> m;
        
        for(int i = 0; i < n; i++) {
            cin >> t;
            
            p.first = t;
            p.second = i;

            v.push_back(p);
        }

        ans = 1;
        while(v.size() > 0) {
            p = v[0];
            v.erase(v.begin());

            //print most important
            if(find_more_important(v, p) == false) {
                if(p.second == m)
                    break;
                
                ans++;
            }
            else v.push_back(p);
        }
        cout << ans << "\n";

        v.clear();
    }
    return 0;
}
bool find_more_important(vector<pair<int, int>> v, pair<int, int> p) {
    for(pair<int, int> a : v) {
        if(a.first > p.first)
            return true;
    }
    
    return false;
}
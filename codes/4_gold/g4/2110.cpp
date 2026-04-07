/*
2110
공유기 설치
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> place;
bool can_place(int n, int c, int dist);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, c;
    cin >> n >> c;

    place.resize(n);
    for(int i = 0; i < n; i++)
        cin >> place[i];

    sort(place.begin(), place.end());

    int l = 1, r = 1000000001, m;
    while(l+1 < r) {
        m = (l+r)/2;

        if(can_place(n, c-1, m) == true)
            l = m;
        else
            r = m;
    }
    cout << l;

    return 0;
}
bool can_place(int n, int c, int dist) {
    int post = 0;
    for(int cur = 1; cur < n; cur++) {
        if(place[cur]-place[post] >= dist) {
            post = cur;
            
            c--;
        }
        if(c == 0) 
            return true;
    }
    return false;
}
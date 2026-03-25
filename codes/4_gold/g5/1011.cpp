/*
1011
Fly me to the Alpha Centauri
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;

    int x, y, dist, m;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;

        dist = y-x;

        m = 0;
        while(dist/(m+1) >= (m+1))
            m++;
        
        if(dist%m == 0) 
            cout << dist/m + m - 1 << "\n";
        else
            cout << dist/m + m << "\n";
    }
    
    return 0;
}
/*
30802
웰컴 키트
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("IO_files/in.txt", "r", stdin);
    freopen("IO_files/out.txt", "w", stdout);
    
    long long n;
    cin >> n;

    long long temp;
    vector<long long> t_shirt;
    for(int i = 0; i < 6; i++) {
        cin >> temp;
        t_shirt.push_back(temp); 
    }

    long long t, p;
    cin >> t >> p;

    long long cnt = 0;
    for(int i = 0; i < 6; i++) {
        cnt += t_shirt[i]/t;
        
        if(t_shirt[i]%t > 0) {
            cnt++;
        }

    }
    cout << cnt << "\n";
    cout << n/p << " " << n%p;


    return 0;
}
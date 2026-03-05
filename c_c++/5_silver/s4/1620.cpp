/*
1620
나는야 포켓몬 마스터 이다솜
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> MontoNo;
map<int, string> NotoMon;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;

        MontoNo.insert({str, i+1});
        NotoMon.insert({i+1, str});
    }

    for(int i = 0; i < m; i++) {
        cin >> str;

        if(isdigit(str[0]) == true) {
            cout << NotoMon.find(stoi(str))->second << "\n";
        }
        else {
            cout << MontoNo.find(str)->second << "\n";
        }
    }
    
    return 0;
}
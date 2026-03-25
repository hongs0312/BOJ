/*
2071
바둑 문제 예제 생성 프로그램
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("c++/0_IO_files/board.txt", "r", stdin);
    freopen("c++/0_IO_files/in.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    vector<vector<pair<int, int>>> diag(n, vector<pair<int, int>>(n));
    
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int r, c;
    bool flag = false;
    vector<int> place, start = {0, 0, n-1, 0};
    for(int i = 0; i < 2*n - 1; i++) {
        place = start;
        while(place[0] < n && place[1] >= 0) {
            r = place[0]; c = place[1];
            diag[r][c].first = i;

            place[0]++; place[1]--;
        }
        while(place[2] < n && place[3] < n) {
            r = place[2]; c = place[3];
            diag[r][c].second = i;
            
            place[2]++; place[3]++;
        }

        if(i < n-1) {
            start[1]++; start[2]--;
        }
        else {
            start[0]++; start[3]++;
        }
    }

    vector <vector<int>> info(4, vector<int>(2*n-1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(m[i][j] != 0) {
                info[0][i]++;
                info[1][j]++;

                info[2][diag[i][j].first]++;
                info[3][diag[i][j].second]++;
            }
        }
    }

    cout << n << "\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cout << info[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 2; i < 4; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            cout << info[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
/*
2630
색종이 만들기
*/
#include <bits/stdc++.h>

using namespace std;

int v[128][128];
int white, blue;

void check(int r, int c, int n);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    check(0, 0, n);

    cout << white << "\n" << blue;
    
    return 0;
}
void check(int r, int c, int n) {
    bool flag = true;
    int value = v[r][c];

    for(int i = r; i < r+n; i++) {
        if(flag == false) break;

        for(int j = c; j < c+n; j++) {
            if(flag == false) break;
            
            if(v[i][j] != value) {
                flag = false;
                
                int half_n = n/2;
                check(r         , c         , half_n);
                check(r         , c+half_n  , half_n);
                check(r+half_n  , c         , half_n);
                check(r+half_n  , c+half_n  , half_n);
            }
        }
    }

    if(flag == true) {
        if(value == 1)  blue++;
        else            white++;
    }
}

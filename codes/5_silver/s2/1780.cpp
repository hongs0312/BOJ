/*
1780
종이의 개수
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<vector<int>> plain;
int cnt[] = {0, 0, 0};

void solve(int r, int c, int k);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    int n;
    cin >> n;

    plain.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            cin >> plain[i][j];

            plain[i][j]++;
        }
    }
    solve(0, 0, n);

    for(int i = 0; i < 3; i++)
        cout << cnt[i] << "\n";

    return 0;
}
void solve(int r, int c, int k) {
    bool flag = true;
    int guide = plain[r][c];
    for(int i = r; i < r+k; i++) {
        for(int j = c; j < c+k; j++) {
            if(plain[i][j] != guide) {
                flag = false;

                break;
            }
        }
        if(flag == false) break;
    }
    if(flag == true) {
        cnt[guide]++;

        return;
    }

    int n_k = k/3;
    for(int n_r = r; n_r < r+k; n_r += n_k)
        for(int n_c = c; n_c < c+k; n_c += n_k)
            solve(n_r, n_c, n_k);
}
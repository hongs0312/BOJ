/*
1992
쿼드트리
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<vector<int>> plain;

string get_quadtree(int r, int c, int k);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    plain.assign(n, vector<int>(n));

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++)
            plain[i][j] = s[j]-'0';
    }
    cout << get_quadtree(0, 0, n);

    return 0;
}
string get_quadtree(int r, int c, int k) {
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
    if(flag == true)
        return to_string(guide);

    string ret = "(";
    
    int half = k/2;
    for(int n_r = r; n_r < r+k; n_r += half) {
        for(int n_c = c; n_c < c+k; n_c += half)
            ret += get_quadtree(n_r, n_c, half);
    }
    ret += ")";

    return ret;
}
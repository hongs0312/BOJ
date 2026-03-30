/*
16139
인간-컴퓨터 상호작용
*/
#include <bits/stdc++.h>

#define ALPHABET 26

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<int>> cnt;

void make_cnt(string &s);
int get_cnt(char c, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    string s;
    cin >> s;
    make_cnt(s);

    int q;
    cin >> q;

    char c;
    int l, r;
    for(int i = 0; i < q; i++) {
        cin >> c >> l >> r;
        
        cout << get_cnt(c, l, r) << "\n";
    }

    return 0;
}
void make_cnt(string &s) {
    int n = s.length();

    cnt.assign(ALPHABET, vector<int>(n+1, 0));

    int c_idx;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < ALPHABET; i++)
            cnt[i][j+1] = cnt[i][j];
        
        c_idx = s[j] - 'a';
        cnt[c_idx][j+1] += 1; 
    }
}
int get_cnt(char c, int l, int r) {
    int i = c-'a';

    return cnt[i][r+1]-cnt[i][l];
}
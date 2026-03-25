/*
14889
스타트와 링크
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int diff = 0x7fffffff;

vector<int> t1, t2;
vector<vector<int>> abil;

int add_abil(vector<int> &v, int n, int new_mem);
void solve(int n, int idx, int t1_score, int t2_score, int t1_size, int t2_size);
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    int n;
    cin >> n;

    t1.resize(n/2);
    t2.resize(n/2);

    abil.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> abil[i][j];
    }
    solve(n, 0, 0, 0, 0, 0);
    cout << diff;

    return 0;
}
int add_abil(vector<int> &v, int n, int new_mem) {
    int ret = 0;
    for(int i = 0; i < n; i++)
        ret += abil[new_mem][v[i]] + abil[v[i]][new_mem];
    
    return ret;
}
void solve(int n, int idx, int t1_score, int t2_score, int t1_size, int t2_size) {
    if(n - t1_size == idx - t2_size) {
        if(t1_size < t2_size) {
            for(; idx < n; idx++) {
                t1[t1_size] = idx;
                t1_score += add_abil(t1, t1_size, idx);
                t1_size++;
            }
        }
        else if(t1_size > t2_size) {
            for(; idx < n; idx++) {
                t2[t2_size] = idx;
                t2_score += add_abil(t2, t2_size, idx);
                t2_size++;
            }
        }
        diff = min(abs(t1_score-t2_score), diff);

        return;
    }

    int tmp;
    if(t1_size < n/2) {
        t1[t1_size] = idx;
        tmp = add_abil(t1, t1_size, idx);
        solve(n, idx+1, t1_score+tmp, t2_score, t1_size+1, t2_size);
    }
    if(t2_size < n/2) {
        t2[t2_size] = idx;
        tmp = add_abil(t2, t2_size, idx);
        solve(n, idx+1, t1_score, t2_score+tmp, t1_size, t2_size+1);
    }
}
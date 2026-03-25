/*
14888
연산자 끼워넣기
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> nums, operators(4);
vector<vector<int>> dp;

void solve(int n, int idx);
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    for(int i = 0; i < 4; i++)
        cin >> operators[i];




    return 0;
}
void solve(int n, int idx) {
    
}
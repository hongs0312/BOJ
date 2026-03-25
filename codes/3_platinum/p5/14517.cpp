/*
14517
팰린드롬 개수 구하기(Large)
*/
#include <bits/stdc++.h>

#define MOD 10007

using namespace std;

typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int dp;

string s;
int go(int front, int rear);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    cin >> s;

    int n = s.length();

    dp.assign(n, v_int(n, -1));

    cout << go(0, n-1);

    return 0;
}
int go(int front, int rear) {
    if(front > rear)
        return 0;

    if(front == rear)
        return 1;

    int& ret = dp[front][rear];

    if(ret != -1)
        return ret;

    ret = 0;
    ret = go(front, rear-1)%MOD + go(front+1, rear);
    ret %= MOD;

    if(s[front] == s[rear])
        ret += 1;
    else {
        ret += MOD;
        ret -= go( front+1, rear-1);
    }
    ret %= MOD;

    return ret;
}
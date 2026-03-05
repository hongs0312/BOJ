/*
1086
박성원
*/
#include <bits/stdc++.h>

#define MAX 0xffff

using namespace std;

typedef long long ll;
typedef vector<string> str_v;
typedef pair<int, int> int_p;

vector<vector<ll>> dp;
vector<int> dex_mod, str_mod; //dex_mod[i] == 10^i % k의 값, str_mod == s[i] % k 값

ll get_fac(int n);
ll GCD(ll a, ll b);
int get_str_mod(string s, int m);
void get_dp(str_v s, int k);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;

    str_v input(n);
    for(int i = 0; i < n; i++)
        cin >> input[i];

    int k;
    cin >> k;

    dex_mod.push_back(1);
    for(int i = 1; i <= 50; i++)
        dex_mod.push_back((dex_mod[i-1]*10) % k);

    for(int i = 0; i < n; i++)
        str_mod.push_back(get_str_mod(input[i], k));

    dp.assign(MAX, vector<ll>(k));

    get_dp(input, k);

    int m_idx = (1 << n) - 1;

    ll n_fac = get_fac(n);
    ll gcd = GCD(dp[m_idx][0], n_fac);

    cout << dp[m_idx][0]/gcd << "/" << get_fac(n)/gcd;

    return 0;
}
ll get_fac(int n) {
    ll result = 1;

    while(n > 0) {
        result *= n;

        n--;
    }
    return result;
}
ll GCD(ll a, ll b) {
    if(b == 0) return a;
    
    ll tmp = a % b;

    return GCD(b, tmp);
}
int get_str_mod(string s, int m) {
    int result = 0;
    
    for(int i = 0; i < s.length(); i++) {
        result *= 10;
        result += s[i] - '0';
        result %= m;
    }
    return result;
}
void get_dp(str_v s, int k) {
    int n = s.size();

    dp[0][0] = 1;

    int next, n_k;
    for(int cur = 0; cur < (1 << n); cur++) {
        for(int i = 0; i < n; i++) {
            if((cur & (1 << i)) == 0) {
                next = cur + (1 << i);

                for(int j = 0; j < k; j++) {
                    n_k = ((j*dex_mod[s[i].length()])%k + str_mod[i])%k;

                    dp[next][n_k] += dp[cur][j];
                }
            }
        }
    }
}
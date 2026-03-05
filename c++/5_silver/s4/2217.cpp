/*
2217
로프
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(ll &a, ll &b) {
    return a > b;
}
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ll n;
    cin >> n;

    vector<ll> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end(), cmp);

    ll input, max_weight= 0;
    for(int i = 0; i < n; i++)
        max_weight = max(nums[i]*(i+1), max_weight);

    cout << max_weight;

    return 0;
}
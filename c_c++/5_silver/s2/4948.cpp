/*
4948
베르트랑 공준
*/
#include <bits/stdc++.h>
#define MAX 250000

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

vector<bool> nums (MAX, true);
vector<ll> primes, prime_cnt(MAX);

void get_primes();
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    get_primes();

    int idx = 0;
    for(int i = 0; i < MAX; i++) {
        if(i == primes[idx])
            idx++;

        prime_cnt[i] = idx;
    }

    int n;
    while(true) {
        cin >> n;

        if(n == 0) break;

        cout << prime_cnt[2*n] - prime_cnt[n] << "\n";
    }

    return 0;
}
void get_primes() {
    nums[0] = nums[1] = false;

    for(int i = 2; i*i < MAX; i++) {
        if(nums[i] == false) continue;

        for(int j = 2*i; j < MAX; j += i)
            nums[j] = false;
    }
    for(int i = 0; i < MAX; i++)
        if(nums[i] == true)
            primes.push_back(i);
}
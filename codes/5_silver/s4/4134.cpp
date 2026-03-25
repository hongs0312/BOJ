/*
4134
다음 소수
*/
#include <bits/stdc++.h>

#define MAX 60000

using namespace std;

typedef long long ll;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<bool> nums (MAX, true);
vector<ll> primes;

void get_primes();
ll next_prime(ll num);
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    get_primes();

    int n;
    cin >> n;

    ll num;
    for(int i = 0; i < n; i++) {
        cin >> num;
    
        cout << next_prime(num) << "\n";
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
bool is_prime(ll num) {
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i]*primes[i] > num)
            break;

        if(num%primes[i] == 0)
            return false;
    }
    return true;
}
ll next_prime(ll num) {
    if(num <= 2) return 2;

    while(true) {
        if(is_prime(num) == true)
            return num;
        
        num++;
    }
}
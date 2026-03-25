/*
17103
골드바흐 파티션
*/
#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

vector<bool> is_prime (MAX, true);
vector<ll> primes;

void get_primes();
int get_partition(int num);
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    get_primes();

    int t;
    cin >> t;

    int n;
    while(t-- > 0) {
        cin >> n;

        cout << get_partition(n) << "\n";
    }

    return 0;
}
void get_primes() {
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i*i < MAX; i++) {
        if(is_prime[i] == false) continue;

        for(int j = 2*i; j < MAX; j += i)
            is_prime[j] = false;
    }
    for(int i = 0; i < MAX; i++)
        if(is_prime[i] == true)
            primes.push_back(i);
}
int get_partition(int num) {
    int tmp, cnt = 0;
    
    //에라토스테네스의 체로 푼 경우
    for(int i = 0; i < primes.size(); i++) {
        tmp = num-primes[i];
        
        if(tmp < num/2) break;
        
        if(is_prime[tmp] == true)
            cnt++;
    }

    //두 포인터로 푼 경우
    // int l = 0, r = primes.size() - 1;
    // while(l <= r) {
    //     tmp = primes[l] + primes[r];

    //     if(tmp == num) {
    //         cnt++;

    //         l++; r--;
    //     }
    //     else if(tmp < num)
    //         l++;
    //     else if(tmp > num)
    //         r--;
    // }
    return cnt;
}
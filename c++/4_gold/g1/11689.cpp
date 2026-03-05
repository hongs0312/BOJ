/*
11689
GCD(n, k) = 1
*/
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

vector<long long> primes;

void get_prime_num(long long n);
vector<long long> prime_factorize(long long n);
long long get_pi_func(long long n);

int main() {
    freopen("../../0_IO_files/in.txt", "r", stdin);
    freopen("../../0_IO_files/out.txt", "w", stdout);
    
    long long n;
    cin >> n;
    
    get_prime_num(MAX);
    cout << get_pi_func(n);

    return 0;
}

void get_prime_num(long long n) { //get prime numbers using sieve of Eratosthenes
    bool is_not_prime[MAX];
    is_not_prime[0] = is_not_prime[1] = true;

    for (long long i = 2; i*i <= n; i++) {
        if(is_not_prime[i] == false) {
            for(long long j = i*2; j <= n; j += i) {
                is_not_prime[j] = true;
            }
        }
    }

    for(long long i = 1; i <= n; i ++) {
        if(is_not_prime[i] == false) {
            primes.push_back(i);
        }
    }
}

vector<long long> prime_factorize(long long n) {
    vector<long long> factors;

    for(long long prime:primes) {
        if(n == 1) break;

        if (n % prime == 0) 
            factors.push_back(prime);

        while(n % prime == 0)
            n /= prime;
    }

    if(n > 1)
        factors.push_back(n);

    return factors;
}

//get pi func ref: https://namu.wiki/w/%EC%98%A4%EC%9D%BC%EB%9F%AC%20%ED%94%BC%20%ED%95%A8%EC%88%98
long long get_pi_func(long long n) {
    vector<long long> factors; //gethering prime factors

    factors = prime_factorize(n);

    long long ans = n;

    for(long long prime:factors) {
        ans /= prime;
        ans *= (prime - 1);
    }

    return ans;
}
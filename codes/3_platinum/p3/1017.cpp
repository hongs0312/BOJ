/*
1017
소수 쌍
*/
#include <bits/stdc++.h>

#define MAX 2001

using namespace std;

typedef long long ll;
typedef vector<int> v_int;
typedef vector<v_int> m_int;

m_int adj;
v_int matched, visited, a, b;

vector<bool> isPrime(MAX, true);

void get_prime();
void get_edge(int u, int v);
int bipartite_matching(int n);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    get_prime();

    int n;
    cin >> n;

    v_int nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    //prime == odd(except 2, but all number are presented once, so no case of 2)
    //odd == odd + even -> so seperating odd and even can reduce calculation
    for(int i = 0; i < n; i++)
        ((nums[i] & 1)?a:b).push_back(nums[i]);

    if(a.size() != b.size()) {
        cout << -1;

        return 0;
    }

    if(b[0] == nums[0]) swap(a, b);

    int max_matching = nums.size() >> 1;

    v_int ans;
    int i = 1;
    for(int j = 1; j <= b.size(); j++) {
        if(isPrime[a[i-1]+b[j-1]] == false) 
            continue;

        get_edge(i, j);

        if(bipartite_matching(a.size())+1 == max_matching)
            ans.push_back(b[j-1]);
    }
    sort(ans.begin(), ans.end());

    if(ans.size() == 0)
        cout << -1;
    else
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

    return 0;
}
void get_prime() {
    int n = isPrime.size();

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < sqrt(n); i++) {
        if(isPrime[i] == true) {
            for(int j = 2*i; j < n; j += i)
                isPrime[j] = false;
        }
    }
}
void get_edge(int u, int v) {
    adj.assign(a.size()+1, v_int());

    matched.assign(b.size()+1, 0);
    matched[v] = u;

    for(int i = 1; i <= a.size(); i++) {
        if(i == u) continue;

        for(int j = 1; j <= b.size(); j++) {
            if(j == v) continue;

            if(isPrime[a[i-1]+b[j-1]] == true)
                adj[i].push_back(j);
        }
    }
}
bool dfs(int cur) {
    visited[cur] = 1;

    for(int next:adj[cur]) {
        if(visited[matched[next]] == 1) continue;

        if(matched[next] == 0 || dfs(matched[next])) {
            matched[next] = cur;

            return true;
        }
    }
    return false;
}
int bipartite_matching(int n) {
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        visited.assign(n+1, 0);
        
        if(dfs(i) == true) ans++;
    }
    return ans;
}
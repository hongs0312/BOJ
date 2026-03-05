/*
1135
뉴스 전하기
*/
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> dp;

bool compare(int a, int b) {
    return a > b;
}
void dfs(int node, int parent);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    adj.resize(n);
    dp.resize(n);
    
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;

        if(input == -1) continue;

        adj[i].push_back(input);
        adj[input].push_back(i);
    }
    dfs(0, -1);
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
void dfs(int node, int parent) {
    vector<int> times = {0};

    for(int next:adj[node]) {
        if(next == parent) continue;

        dfs(next, node);

        times.push_back(dp[next]+1);
    }
    sort(times.begin(), times.end(), compare);

    for(int i = 0; i < times.size(); i++) {
        times[i] += i;
    }

    dp[node] = *max_element(times.begin(), times.end());
}
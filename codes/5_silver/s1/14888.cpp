/*
14888
연산자 끼워넣기
*/
#include <bits/stdc++.h>
#define INF 0x7fffffff

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef enum Operators{
    plus,
    minus,
    multi,
    divid
} Operators;

typedef long long ll;

vector<Operators> selected;
vector<ll> nums, ops(4);

ll max_num = -INF, min_num = INF;

void solve(int n, int idx);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n;

    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    for(int i = 0; i < 4; i++)
        cin >> ops[i];

    selected.resize(n-1);
    solve(n-1, 0);
    cout << max_num << "\n" << min_num;

    return 0;
}
ll get_result(vector<Operators> &v) {
    int n = v.size();

    ll ret = nums[0];
    for(int i = 0; i < n; i++) {
        switch (v[i]) {
        case Operators::plus:
            ret += nums[i+1];
            break;
        case Operators::minus:
            ret -= nums[i+1];
            break;
        case Operators::multi:
            ret *= nums[i+1];
            break;
        case Operators::divid:
            ret /= nums[i+1];
            break;
        }
    }
    return ret;
}
void solve(int n, int idx) {
    if (idx == n) {
        ll tmp = get_result(selected);

        max_num = max(tmp, max_num);
        min_num = min(tmp, min_num);

        return;
    }
    if(ops[Operators::plus] > 0) {
        selected[idx] = Operators::plus;
        ops[Operators::plus] -= 1;
        
        solve(n, idx+1);

        ops[Operators::plus] += 1;
    }

    if(ops[Operators::minus] > 0) {
        selected[idx] = Operators::minus;
        ops[Operators::minus] -= 1;
        
        solve(n, idx+1);

        ops[Operators::minus] += 1;
    }

    if(ops[Operators::multi] > 0) {
        selected[idx] = Operators::multi;
        ops[Operators::multi] -= 1;
        
        solve(n, idx+1);

        ops[Operators::multi] += 1;
    }

    if(ops[Operators::divid] > 0) {
        selected[idx] = Operators::divid;
        ops[Operators::divid] -= 1;
        
        solve(n, idx+1);

        ops[Operators::divid] += 1;
    }
}
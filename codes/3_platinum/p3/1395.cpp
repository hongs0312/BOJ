/*
1395
스위치
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
typedef struct {
    int l, r;
    ll cnt, lazy;
} node;

vector<ll> nums;
vector<node> tree;
ll make_tree(int n, int l, int r);
void update_val(int n, int l, int r, int val);
ll get_sum(int n, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    
    int n, m;
    cin >> n >> m;

    nums.assign(n+1, 0);
    tree.resize((n << 2) + 1);
    make_tree(1, 1, n);

    int cmd, a, b;
    for(int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;

        if(cmd == 0)
            update_val(1, a, b, 0);
        else
            cout << get_sum(1, a, b) << "\n";
    }

    return 0;
}
ll make_tree(int n, int l, int r){
    tree[n].l = l;
    tree[n].r = r;

    tree[n].lazy = 0;

    if(l == r)
        tree[n].cnt = nums[l];
    else {
        int m = (l+r) >> 1;

        int l_child = (n << 1);
        int r_child = l_child + 1;

        tree[n].cnt = 0;
        tree[n].cnt += make_tree(l_child, l, m);
        tree[n].cnt += make_tree(r_child, m+1, r);
    }

    return tree[n].cnt;
}
void update_val(int n, int l, int r, int val) {
    if(tree[n].l >= l && tree[n].r <= r) {
        tree[n].lazy += val;

        return;
    }
    else if(tree[n].l > r || tree[n].r < l)
        return;

    int l_child = (n << 1);
    int r_child = l_child + 1;

    update_val(l_child, l, r, val);
    update_val(r_child, l, r, val);
}
ll get_sum(int n, int l, int r) {
    int l_child = (n << 1);
    int r_child = l_child + 1;

    if(l_child < tree.size())
        tree[l_child].lazy += tree[n].lazy;
    if(r_child < tree.size())
        tree[r_child].lazy += tree[n].lazy;

    tree[n].cnt += tree[n].lazy*(r-l+1);
    tree[n].lazy = 0;

    if(tree[n].l >= l && tree[n].r <= r)
        return tree[n].cnt;
    else if(tree[n].l > r || tree[n].r < l)
        return 0;

    return get_sum(l_child, l, r) + get_sum(r_child, l, r);
}
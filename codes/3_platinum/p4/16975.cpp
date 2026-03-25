/*
16975
수열과 쿼리 21
*/
#include <bits/stdc++.h>

using namespace std;

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
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    nums.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    tree.resize((n << 2) + 1);
    make_tree(1, 1, n);

    int m, a, b, c, d;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;

            update_val(1, b, c, d);
        }
        else {
            cin >> b;

            cout << get_sum(1, b, b) << "\n";
        }
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
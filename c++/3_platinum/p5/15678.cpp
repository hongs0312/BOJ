/*
15678
연세워터파크
*/
#include <bits/stdc++.h>

#define INF 0x7fffffff

using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef struct node {
    int l, r;
    ll value;
}node;
vector<node> tree;

v_ll dp;

void make_tree(int n, int l, int r);
void update_value(int n, int l, int r, ll value);
ll get_max(int n, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    //fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n >> d;
    
    //get input
    dp.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> dp[i];

    //make segment tree
    tree.resize((n << 2) + 1);
    make_tree(1, 1, n);

    //get dp
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i]+get_max(1, i-d, i-1), dp[i]);

        update_value(1, i, i, dp[i]);
    }

    //output
    cout << get_max(1, 1, n);

    return 0;
}
void make_tree(int n, int l, int r) {
    tree[n].l = l;
    tree[n].r = r;

    if(l == r) {
        tree[n].value = dp[l];

        return;
    }
    int m = (l+r) >> 1;

    int l_child = n << 1;
    int r_child = l_child + 1;

    make_tree(l_child, l, m);
    make_tree(r_child, m+1, r);

    tree[n].value = max(tree[l_child].value, tree[r_child].value);
}
void update_value(int n, int l, int r, ll value) {
    //if get in range
    if(tree[n].l >= l && tree[n].r <= r) {
        tree[n].value = value;

        return;
    }
    //if out of range
    if(tree[n].l > r || tree[n].r < l)
        return;

    int l_child = n << 1;
    int r_child = l_child + 1;

    update_value(l_child, l, r, value);
    update_value(r_child, l, r, value);

    tree[n].value = max(tree[l_child].value, tree[r_child].value);
}
ll get_max(int n, int l, int r) {
    //if get in range
    if(tree[n].l >= l && tree[n].r <= r)
        return tree[n].value;

    //if out of range
    if(tree[n].l > r || tree[n].r < l)
        return -INF;

    int l_child = n << 1;
    int r_child = l_child + 1;

    return max(get_max(l_child, l, r), get_max(r_child, l, r));
}
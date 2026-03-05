/*
3653
영화 수집
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> v_int;
typedef struct node {
    int l, r;
    ll cnt;
} node;

v_int dvd, idx;
vector<node> tree;
void make_tree(int n, int l, int r);
ll update_val(int n, int idx, int val);
ll get_sum(int n, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r;
    cin >> r;

    int n, m, num;
    while(r-- > 0) {
        cin >> n >> m;
        
        idx.assign(n+1, 0);
        dvd.assign(n+m+1, 0);
        for(int i = 1; i <= n; i++) {
            idx[i] = m+i;
            dvd[m+i] = 1;
        }

        tree.resize(((n+m) << 2) + 2);
        make_tree(1, 0, n+m);

        for(int i = 0; i < m; i++) {
            cin >> num;

            cout << get_sum(1, 0, idx[num]-1) << " ";

            update_val(1, idx[num], 0);
            update_val(1, m-i,  1);

            idx[num] = m-i;
        }
        cout << "\n";
    }
    return 0;
}
void make_tree(int n, int l, int r){
    tree[n].l = l;
    tree[n].r = r;

    if(l == r) {
        tree[n].cnt = dvd[l];
        return;
    }

    int m = (l+r) >> 1;

    int l_child = (n << 1);
    int r_child = l_child + 1;

    make_tree(l_child, l, m);
    make_tree(r_child, m+1, r);

    tree[n].cnt = tree[l_child].cnt + tree[r_child].cnt;
}
ll update_val(int n, int idx, int val) {
    if(tree[n].l == idx && tree[n].r == idx) {
        tree[n].cnt = val;
    }
    else if(tree[n].l <= idx && tree[n].r >= idx) {
        int l_child = (n << 1);
        int r_child = l_child + 1;

        tree[n].cnt = 0;
        tree[n].cnt += update_val(l_child, idx, val);
        tree[n].cnt += update_val(r_child, idx, val);
    }
    return tree[n].cnt;
}
ll get_sum(int n, int l, int r) {
    if(tree[n].l >= l && tree[n].r <= r)
        return tree[n].cnt;
    else if(tree[n].l > r || tree[n].r < l)
        return 0;

    int l_child = (n << 1);
    int r_child = l_child + 1;

    return get_sum(l_child, l, r) + get_sum(r_child, l, r);
}
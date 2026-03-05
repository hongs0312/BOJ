/*
segment_tree 알고리즘 구현체
*/
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

typedef long long ll;
typedef struct {
    int l, r;
    ll cnt;
} node;

vector<node> tree;
void make_tree(int n, int l, int r);
ll update_val(int n, int idx, int val);
ll get_sum(int n, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    tree.resize((n << 2) + 1);
    make_tree(1, 0, n-1);

    return 0;
}
void make_tree(int n, int l, int r){
    tree[n].l = l;
    tree[n].r = r;

    tree[n].cnt = 0;

    if(l == r) return;

    int m = (l+r) >> 1;

    int l_child = (n << 1);
    int r_child = l_child + 1;

    make_tree(l_child, l, m);
    make_tree(r_child, m+1, r);
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
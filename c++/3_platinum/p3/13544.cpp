/*
13544
수열과 쿼리 3
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v_int;
typedef struct element{
    int l, r;
    v_int num;
}element;
typedef vector<element> v_elem;

v_elem seg_tree;
v_int nums;

void make_seg_tree(int n, int l, int r);
int get_value(int n, int l, int r, int k);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    nums.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    seg_tree.resize(4*n);
    make_seg_tree(1, 1, n);

    int m;
    cin >> m;

    int a, b, k, last = 0;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> k;

        last = get_value(1, a^last, b^last, k^last);
        
        cout << last << "\n";
    }

    return 0;
}
void make_seg_tree(int n, int l, int r){
    seg_tree[n].l = l;
    seg_tree[n].r = r;

    if(l == r) {
        seg_tree[n].num.push_back(nums[l]);

        return;
    }

    int m = (l+r)/2;
    int l_child = 2*n, r_child = 2*n + 1;

    make_seg_tree(l_child, l, m);
    make_seg_tree(r_child, m+1, r);

    int l_tmp, r_tmp, l_idx = 0, r_idx = 0;
    while(l_idx < m-l+1 && r_idx < r-m) {
        l_tmp = seg_tree[l_child].num[l_idx];
        r_tmp = seg_tree[r_child].num[r_idx];

        if(l_tmp <= r_tmp) {
            seg_tree[n].num.push_back(l_tmp);
            l_idx++;
        }
        else {
            seg_tree[n].num.push_back(r_tmp);
            r_idx++;
        }
    }
    while(l_idx < m-l+1) {
        l_tmp = seg_tree[l_child].num[l_idx];
        seg_tree[n].num.push_back(l_tmp);
        l_idx++;
    }
    while(r_idx < r-m) {
        r_tmp = seg_tree[r_child].num[r_idx];
        seg_tree[n].num.push_back(r_tmp);
        r_idx++;
    }
}
int get_bigger_cnt(v_int* v, int k) {
    int l = 0, r = (*v).size()-1;
    
    int m;
    while(l < r) {
        m = (l+r)/2;

        if((*v)[m] <= k) l = m+1;
        else if((*v)[m] > k) r = m-1;
    }
    if((*v)[l] <= k)
        return (*v).size()-l-1;
    else
        return (*v).size()-l;
}
int get_value(int n, int l, int r, int k) {
    int l_range = seg_tree[n].l;
    int r_range = seg_tree[n].r;

    if(l_range >= l && r_range <= r)
        return get_bigger_cnt(&(seg_tree[n].num), k);

    int ret = 0, l_child = 2*n, r_child = 2*n + 1;
    if(l <= seg_tree[l_child].r)
        ret += get_value(l_child, l, r, k);

    if(r >= seg_tree[r_child].l)
        ret += get_value(r_child, l, r, k);
        
    return ret; 
}
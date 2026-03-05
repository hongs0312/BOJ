/*
2243
사탕상자
*/
#include <bits/stdc++.h>

#define MAX 1 << 20

using namespace std;

typedef struct node* n_ptr;
typedef struct node {
    int cnt;
    int l, r;
    n_ptr l_child, r_child;
}node;

n_ptr root;

n_ptr create_tree(int l, int r);
void put_in(n_ptr n, int taste, int cnt, int l, int r);
int pick_one(n_ptr n, int candy);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    root = create_tree(1, MAX);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    int n;
    cin >> n;

    int a, b, c;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a == 1) {
            cout << pick_one(root, b) << "\n";
        }
        else if(a == 2) {
            cin >> c;

            put_in(root, b, c, 1, MAX);     
        }
    }

    return 0;
}
n_ptr create_node(int l, int r) {
    n_ptr tmp = (n_ptr)malloc(sizeof(node));

    tmp->l = l;
    tmp->r = r;

    tmp->cnt = 0;
    tmp->l_child = tmp->r_child = NULL;

    return tmp;
}
n_ptr create_tree(int l, int r){
    n_ptr tmp = create_node(l, r);

    if(l == r) return tmp;

    int m = (l+r)/2;

    tmp->l_child = create_tree(l, m);
    tmp->r_child = create_tree(m+1, r); 

    return tmp;
}
void put_in(n_ptr n, int taste, int cnt, int l, int r) {
    if(l == r) {
        n->cnt += cnt;

        return;
    }

    int m = (l+r)/2;
    if(taste <= m)
        put_in(n->l_child, taste, cnt, l, m);
    else
        put_in(n->r_child, taste, cnt, m+1, r);

    n->cnt = n->l_child->cnt + n->r_child->cnt;

    return;
}
int pick_one(n_ptr n, int candy) {
    int l = n->l, r = n->r;

    if(l == r) {
        n->cnt -= 1;

        return l;
    }

    int result, m = (l+r)/2;
    if(candy <= n->l_child->cnt)
        result = pick_one(n->l_child, candy);
    else
        result = pick_one(n->r_child, candy - n->l_child->cnt);
        
    n->cnt = n->l_child->cnt + n->r_child->cnt;

    return result;
}
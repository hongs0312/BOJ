/*
10999
구간 합 구하기 2
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct node* nodeptr;
typedef struct node {
    int begin, end;
    
    long long sum;
    long long lazy;

    nodeptr left, right;
}node;

long long range_sum[1000001];
nodeptr root;

nodeptr make_node(int begin, int end, long long sum);
nodeptr make_seg_tree(int begin, int end);
long long mod_the_tree(nodeptr cur, int begin, int end, long long mod_val);
long long get_sum(nodeptr cur, int begin, int end);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    long long input;
    for(int i = 1; i <= n; i++) {
        cin >> input;

        range_sum[i] = range_sum[i-1] + input;
    }

    root = make_seg_tree(1, n);

    int a, b, c;
    long long d;
    for(int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;

        if(a == 1) {
            cin >> d;

            mod_the_tree(root, b, c, d);
        }
        if(a == 2) {
            cout << get_sum(root, b, c) << "\n";
        }
    }

    return 0;
}
//make a tree's node
nodeptr make_node(int begin, int end, long long sum) {
    nodeptr temp = new node;

    temp->begin = begin;
    temp->end = end;
    
    temp->sum = sum;
    temp->lazy = 0;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
//make a segment tree
nodeptr make_seg_tree(int begin, int end){
    long long sum = range_sum[end] - range_sum[begin-1];
    nodeptr temp = make_node(begin, end, sum);

    if(begin != end) {
        int mid = (begin+end)/2;

        temp->left = make_seg_tree(begin, mid);
        temp->right = make_seg_tree(mid+1, end);
    }
    
    return temp;
}
//transfer the lazy value
void push(nodeptr n_node) {
    int begin = n_node->begin;
    int end = n_node->end;

    if(n_node->left)
        n_node->left->lazy += n_node->lazy;

    if(n_node->right)
        n_node->right->lazy += n_node->lazy;
    
    n_node->sum += (n_node->lazy)*(end-begin+1);
    n_node->lazy = 0;
}
//modify node's sum when visiting the node
long long mod_the_tree(nodeptr cur, int begin, int end, long long mod_val) {
    int c_b = cur->begin;
    int c_e = cur->end;
    
    //out of range
    if(begin > c_e || end < c_b) {
        push(cur);

        return cur->sum;
    }

    //in the range
    if(begin <= c_b && end >= c_e) {
        cur->lazy += mod_val;

        //if current node has child, transfer it's lazy value
        push(cur);

        return cur->sum;
    }

    int l_end = cur->left->end;
    int r_begin = cur->right->begin;
    
    push(cur);
    
    long long sum = 0;
    sum += mod_the_tree(cur->left, begin, end, mod_val);
    sum += mod_the_tree(cur->right, begin, end, mod_val);

    cur->sum = sum;

    return sum;
}

long long get_sum(nodeptr cur, int begin, int end) {
    int c_b = cur->begin;
    int c_e = cur->end;

    //out of range
    if(begin > c_e || end < c_b)
        return 0;   
    
    //in the rnage
    if(begin <= c_b && end >= c_e) {
        push(cur);

        //return sum value
        return cur->sum;
    }
    
    int l_end = cur->left->end;
    int r_begin = cur->right->begin;
    
    push(cur);
    
    //getting sum;
    long long sum = 0;
    sum += get_sum(cur->left, begin, end);
    sum += get_sum(cur->right, begin, end);        
    
    return sum;
}
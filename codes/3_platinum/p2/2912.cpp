/*
2912
백설공주와 난쟁이
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
typedef pair<int, int> p_int;
typedef vector<int> v_int;
typedef vector<v_int> m_int;
typedef struct query {
    int idx;
    p_int range;
} query;

int sqn;
v_int nums, num_cnt;

bool cmp(query &a, query &b);
int check(int c, int half);
void count_in(int s, int e);
void count_out(int s, int e);
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n, c;
    cin >> n >> c;

    num_cnt.resize(c+1);

    sqn = int(sqrt(n));
    
    nums.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    int m, a, b;
    cin >> m;

    vector<query> querys;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;

        querys.push_back({i, {a, b}});
    }
    sort(querys.begin(), querys.end(), cmp);

    v_int ans(m);

    p_int cur, post = {0, 0};
    for(query q:querys) {
        cur = q.range;

        if(cur.first < post.first) 
            count_in(cur.first, post.first-1);
        if(cur.first > post.first)
            count_out(post.first, cur.first-1);
        
        if(cur.second > post.second) 
            count_in(post.second+1, cur.second);
        if(cur.second < post.second)
            count_out(cur.second+1, post.second);

        ans[q.idx] =  check(c, (cur.second-cur.first+1)/2);
        post = cur;
    }
    for(int i:ans) {
        if(i == 0) cout << "no\n";
        else cout << "yes " << i << "\n";
    }
    return 0;
}
bool cmp(query &a, query &b) {
    p_int a_r = a.range, b_r = b.range;
    if(a_r.first/sqn != b_r.first/sqn)
        return a_r.first < b_r.first;

    return a_r.second < b_r.second;
}
int check(int c, int half) {
    for(int i = 1; i <= c; i++) {
        if(num_cnt[i] > half)
            return i;
    }
    return 0;
}
void count_in(int s, int e) {
    int cnt;
    for(int i = s; i <= e; i++)
        num_cnt[nums[i]]++;
}
void count_out(int s, int e) {
    for(int i = s; i <= e; i++)
        num_cnt[nums[i]]--;
}
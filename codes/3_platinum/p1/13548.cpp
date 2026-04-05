/*
13548
수열과 쿼리 6
*/
#include <bits/stdc++.h>

#define MAX 1000001

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

int sqn, top_cnt = 0;
v_int nums, num_cnt, cnt_cnt;
bool cmp(query &a, query &b);
void count_in(int s, int e);
void count_out(int s, int e);
int main() {
    #ifdef SH_LOCAL
    freopen("0_IO_files/in.txt", "r", stdin);
    freopen("0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();
    num_cnt.resize(MAX);

    int n;
    cin >> n;

    sqn = int(sqrt(n));
    
    cnt_cnt.resize(n+1);
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
        if(cur.second > post.second) 
            count_in(post.second+1, cur.second);

        if(cur.first > post.first)
            count_out(post.first, cur.first-1);
        if(cur.second < post.second)
            count_out(cur.second+1, post.second);

        ans[q.idx] = top_cnt;

        post = cur;
    }
    for(int i:ans) 
        cout << i << "\n";

    return 0;
}
bool cmp(query &a, query &b) {
    p_int a_r = a.range, b_r = b.range;
    if(a_r.first/sqn != b_r.first/sqn)
        return a_r.first < b_r.first;

    return a_r.second < b_r.second;
}
void count_in(int s, int e) {
    int cnt;
    for(int i = s; i <= e; i++) {
        num_cnt[nums[i]]++;

        cnt = num_cnt[nums[i]];

        top_cnt = max(cnt, top_cnt);
        
        cnt_cnt[cnt-1]--;
        cnt_cnt[cnt]++;
    }
}
void count_out(int s, int e) {
    int cnt;
    for(int i = s; i <= e; i++) {
        cnt = num_cnt[nums[i]];

        if(cnt == 0) continue;
        
        cnt_cnt[cnt]--;
        cnt_cnt[cnt-1]++;

        if(cnt_cnt[top_cnt] == 0)
            top_cnt--;

        num_cnt[nums[i]]--;
    }
}
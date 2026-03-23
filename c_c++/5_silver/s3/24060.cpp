/*
24060
알고리즘 수업 - 병합 정렬 1
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef vector<int> v_int;

int k, store_cnt = 0, ans = -1;

void merge_sort(v_int &v, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("c_c++/0_IO_files/in.txt", "r", stdin);
    freopen("c_c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int n;
    cin >> n >> k;

    v_int v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    merge_sort(v, 0, n-1);

    cout << ans;

    return 0;
}
void merge(v_int &v, int l, int m, int r) {
    v_int tmp(r - l + 1);

    int i = l, j = m+1, t = 0;
    while(i <= m && j <= r) {
        if(v[i] <= v[j])
            tmp[t++] = v[i++];
        else
            tmp[t++] = v[j++];
    }
    while(i <= m)
        tmp[t++] = v[i++];
    
    while(j <= r)
        tmp[t++] = v[j++];

    t = 0; i = l;
    while(i <= r) {
        v[i++] = tmp[t++];

        store_cnt++;
        if(store_cnt == k)
            ans = tmp[t-1];
    }
}
void merge_sort(v_int &v, int l, int r) {
    if(l < r) {
        int m = (l+r)/2;

        merge_sort(v, l, m);
        merge_sort(v, m+1, r);

        merge(v, l, m, r);
    }
}
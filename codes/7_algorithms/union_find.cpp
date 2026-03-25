/*
union_find 알고리즘 구현체
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v_int;

v_int parent, rank_set;

void init_set(int n);
int find_set(int x);
void union_set(int a, int b);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    init_set(n);

    return 0;
}
void init_set(int n) {
    rank_set.assign(n, 1);
    parent.resize(n);

    for(int i = 0; i < n; i++)
        parent[i] = i;
}
int find_set(int x) {
    //부모가 자기자신이면 자신이 root
    if(parent[x] == x)
        return x;

    //경로 압축
    parent[x] = find_set(parent[x]);

    return parent[x];
}
void union_set(int a, int b) {
    //a와 b의 루트 구하기
    a = find_set(a);
    b = find_set(b);

    //부모가 같으면 return
    if(a == b) return;

    //rank가 더 큰 set이 a에 오게 swap
    if(rank_set[a] < rank_set[b])
        swap(a, b);

    //b를 a아래에 병합
    parent[b] = a;

    if(rank_set[a] == rank_set[b])
        rank_set[a] += 1;
}
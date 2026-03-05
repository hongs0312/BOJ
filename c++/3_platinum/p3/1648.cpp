/*
1648
격자판 채우기

참고한 블로그
https://glanceyes.com/entry/BOJ-%EB%B0%B1%EC%A4%80-1648%EB%B2%88-%EA%B2%A9%EC%9E%90%ED%8C%90-%EC%B1%84%EC%9A%B0%EA%B8%B0
*/

#include <bits/stdc++.h>

#define MOD 9901

using namespace std;

typedef long long ll;
typedef vector<ll> v_ll;
typedef vector<v_ll> m_ll;

m_ll dp;
int n, m, nm;

ll go(int idx, int status);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    cin >> n >> m;

    nm = n*m;
    dp.assign(nm, v_ll((1 << m), -1));

    cout << go(0, 0);

    return 0;
}
ll go(int idx, int status) {
    if(idx >= nm) {
        //정상적으로 끝에 다다름
        if(idx == nm && status == 0)
            return 1;
        
        //이외에는 no count
        return 0;
    }

    ll &ret = dp[idx][status];
    
    //방문한 적 있으면 그대로 값 리턴
    if(ret != -1)
        return ret;

    ret = 0;
    //만약 지금 칸이 차 있다면 다음 칸으로 이동
    if((status & 1) == 1)
        ret += go(idx+1, status >> 1);
    else {
        //if 2x1 블록(가로)을 놓는 경우
        if((idx % m) != (m-1) && (status & (1 << 1)) == 0)
            ret += go(idx + 2, status >> 2);

        //if 1x2 블록(세로)을 놓는 경우
        ret += go(idx + 1, (status >> 1)|(1 << (m-1)));
    }
    ret %= MOD;
    
    return ret;
}
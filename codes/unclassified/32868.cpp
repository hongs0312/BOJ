/*
32868
HCPC 팀 짜기
*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long

using namespace std;

int main() {
    freopen("IO_files/in.txt", "r", stdin);
    freopen("IO_files/out.txt", "w", stdout);

    // n == 상관없는 사람 수 / m == 상관있는 사람 수 / p == 상관 있는 사람 중 서로 원하는 사람의 수
    //1. 상관 없는 사람 n명 중 3명이서 팀을 짜는 경우 n*(n-1)*(n-2)/6
    //2. 노상관 2명, 상관 1명 (m-p)*(n-1)
    
    //3. 노상관 1명, 상관 2명 
    //3-1. 상관 2명이 서로 원하는 경우 p*n/2
    //3-2. 상관 2명이 동일 인물을 원하는 경우 sum(to_me*(to_me-1)) (for all no matters)

    //4 상관 3명 순회하면서 검출

    //1. 리스트 순회하면서 노상관인 사람 수 구하기, 방문 표시
    //2. 깊이가 1인 탐색(다음 노드까지 확인) 다음 노드 만약 노상관 --> 답에 노상관-1 더하기, 방문 표시
    //3. 깊이가 2인 탐색(다다음 노드까지 확인) 만약 출발노드에 도착 --> 페어인 노드 수 1 증가, 방문 표시
    //4. 깊이가 3인 탐색(다다다음 노드까지 확인) 3개의 노드를 담은 뒤 현재 있는 노드가 그 안에 있으면 카운트

    int n;
    cin >> n;
    
    vector<int> v(n);
    vector<bool> visited(n);
    long long no_matter = 0, pair_cnt = 0;
    long long ans = 0; 
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;

        if(v[i] == i) {
            no_matter++;
            visited[i] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == true) continue;

        if(v[i] == v[v[i]]) {
            if(no_matter-1 > 0)
                ans += no_matter-1;

            if(ans > MOD)
                ans /= MOD;

            visited[i] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == true) continue;

        int cur = i;
        for(int j = 0; j < 2; j++)
            cur = v[cur];

        if(cur == i) {
            pair_cnt++;
            visited[i] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == true) continue;
        
        int cur = i;
        vector<int> node;
        for(int j = 0; j < 3; j++) {
            node.push_back(cur);

            cur = v[cur];
        }
        
        for(int j = 0; j < 3; j++) {
            if(node[j] == cur) { 
                ans++;

                if(ans > MOD) 
                    ans /= MOD;
                
                break;
            }
        }
    }

    long long tmp = 1;
    for(int i = 0; i < 3; i++) {
        tmp = (tmp*(no_matter-i))/MOD;
    }
    ans = (ans + tmp/6)/MOD;
    ans = (ans + (pair_cnt*no_matter/2)/MOD)/MOD;

    cout << ans;

    return 0;
}
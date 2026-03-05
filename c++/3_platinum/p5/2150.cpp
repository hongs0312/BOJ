/*
Strongly Connected Component
*/
#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x);
int main(){
    ios::sync_with_stdio(false);

    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= v; i++)
        sort(adj[i].begin(), adj[i].end());
    
    for(int i = 1; i <= v; i++)
        if(d[i] == 0) dfs(i);

    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << '\n';
    for(int i = 0; i < SCC.size(); i++){
        for(int j = 0; j < SCC[i].size(); j++)
            cout << SCC[i][j] << ' ';
        cout << "-1\n";
    }
    return 0;
}
int dfs(int x){
    // id == 방문 순서
    // id가 작음 == 먼저 방문

    d[x] = ++id; //방문한 점 id 부여
    s.push(x); // 스택에 자기 자신 삽입

    int parent = d[x]; //자기자신을 부모로 설정
    for(int i = 0; i < adj[x].size(); i++){ //dfs 시행
        int y = adj[x][i];
        if(d[y] == 0) parent = min(parent, dfs(y)); //방문하지 않은 이웃 -> 방문 후 부모 갱신
        else if(!finished[y]) parent = min(parent, d[y]); //방문은 했지만 아직 SCC에 포함되지 않은 이웃을 만남 -> 부모 갱신
    }

    //부모 노드가 자기 자신인 경우 SCC 형성
    if(parent == d[x]){
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    return parent;
}
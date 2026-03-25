/*
2638
치즈
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> num_p;

vector<vector<int>> space, visited, air_contect_cnt;
vector<int> rr = {0, 0, 1, -1};
vector<int> cc = {1, -1, 0, 0};

queue<pair<int, num_p>> cheesses;
int n, m;

void bfs(int time, num_p p);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    cin >> n >> m;

    space.assign(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> space[i][j];

    visited.assign(n, vector<int>(m, 0));
    air_contect_cnt.assign(n, vector<int>(m, 0));

    cheesses.push({-1, {0, 0}});

    num_p tmp;
    int r, c, time = 0;
    while(true) {
        while(cheesses.size() > 0 && cheesses.front().first < time) {
            tmp = cheesses.front().second;

            r = tmp.first; c = tmp.second;
            space[r][c] = 0;
            visited[r][c] = 1;

            bfs(time, tmp);
            
            cheesses.pop();
        }
        
        if(cheesses.size() == 0)
            break;

        time++;
    }
    cout << time;

    return 0;
}
void bfs(int time, num_p p) {
    queue<num_p> q;

    q.push(p);

    int r, c, n_r, n_c;
    while(q.size() > 0) {
        r = q.front().first;
        c = q.front().second;

        for(int i = 0; i < 4; i++) {
            n_r = r + rr[i];
            n_c = c + cc[i];

            //out of range check
            if(n_r < 0 || n_r >= n || n_c < 0 || n_c >= m) 
                continue;

            //visited check
            if(visited[n_r][n_c] != 0)
                continue;
            
            //detect cheess
            if(space[n_r][n_c] == 1) {
                air_contect_cnt[n_r][n_c]++;

                if(air_contect_cnt[n_r][n_c] >= 2) {
                    cheesses.push({time, {n_r, n_c}});

                    visited[n_r][n_c] = 1;
                }
                continue;
            }
            q.push({n_r, n_c});

            visited[n_r][n_c] = 1;
        }
        q.pop();
    }
}
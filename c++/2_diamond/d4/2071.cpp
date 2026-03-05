/*
2071
바둑 (풀이중)
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;
typedef pair<int, int> num_p;

matrix info, board;
pair<matrix, matrix> diag;

vector<int> rr = {0, 0, 1, -1, 1, 1, -1, -1};
vector<int> cc = {1, -1, 0, 0, 1, -1, 1, -1};

void print_mat(matrix m) {
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[0].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

pair<matrix, matrix> get_diag(int n);
bool find_original(int i, int j, int n, int stones);
int get_house_size(int n);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n, stone_cnt = 0;
    cin >> n;
    
    board.assign(n, vector<int>(n));
    info.assign(4, vector<int>(2*n - 1));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> info[i][j];

            stone_cnt += info[i][j];
        }
    }
    for(int i = 2; i < 4; i++) {
        for(int j = 0; j < 2*n - 1; j++) {
            cin >> info[i][j];
        }
    }
    diag = get_diag(n);

    stone_cnt = stone_cnt >> 1;

    find_original(0, 0, n, stone_cnt);

    print_mat(board);
    cout << get_house_size(n) - stone_cnt;

    return 0;
}
void mod_line(matrix* m, num_p start, num_p diff, int value) {
    int n = (*m).size();

    int r = start.first;
    int c = start.second;

    int rr = diff.first;
    int cc = diff.second;

    while(r >= 0 && r < n && c >= 0 && c < n) {
        (*m)[r][c] += value;
        
        r += rr;
        c += cc;
    }
}
pair<matrix, matrix> get_diag(int n) {
    pair<matrix, matrix> result;

    result.first.assign(n, vector<int>(n, 0));
    result.second.assign(n, vector<int>(n, 0));

    vector<pair<int, int>> start = {{0, 0}, {n-1, 0}};
    for(int i = 0; i < 2*n - 1; i++) {
        mod_line(&result.first, start[0], {1, -1}, i);
        mod_line(&result.second, start[1], {1, 1}, i);

        if(i < n-1) {
            start[0].second++; start[1].first--;
        }
        else {
            start[0].first++; start[1].second++;
        }
    }
    return result;
}
bool info_check(num_p p, int n) {
    int i = p.first, j = p.second;

    if(info[0][i] <= 0 || info[0][i] > n-j)
        return false;
    if(info[1][j] <= 0 || info[1][j] > n-i)
        return false;
    if(info[2][diag.first[i][j]] <= 0 || info[2][diag.first[i][j]] > min(n-i, j))
        return false;
    if(info[3][diag.second[i][j]] <= 0 || info[3][diag.second[i][j]] > min(n-i, n-j))
        return false;

    return true;
}
// cmd == 1 착수, cmd == -1 무르기
void place_stone(num_p p, int cmd) {
    int r = p.first, c = p.second;

    info[0][r] -= cmd;
    info[1][c] -= cmd;

    info[2][diag.first[r][c]] -= cmd;
    info[3][diag.second[r][c]] -= cmd;

    board[r][c] += cmd;
}
bool find_original(int i, int j, int n, int stones) {
    if(stones == 1) 
        return true;

    i += j/n; j %= n;

    if(n*(n-i)+(n-j) < stones) return false;

    for(; i < n; i++) {
        for(; j < n; j++) {
            if(info_check({i, j}, n) == true) {
                place_stone({i, j}, 1);

                if(find_original(i, j+1, n, stones-1) == true)
                    return true;

                place_stone({i, j}, -1);
            }
        }
        j = 0;
    }
    return false;
}
int get_house_size(int n) {
    matrix tmp;
    tmp.assign(n+4, vector<int>(n+4));

    for(int i = 0; i < n+4; i++) {
        tmp[0][i] = tmp[n+3][i] = 1;
        tmp[i][0] = tmp[i][n+3] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[i+2][j+2] = board[i][j];
        }
    }
    
    int r, c, ans = 0;
    pair<int, int> cur;
    queue<pair<int, int>> q;
    q.push({1, 1}); tmp[1][1] = 1;
    while(q.size() > 0) {
        cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            r = cur.first + rr[i];
            c = cur.second + cc[i];

            if(tmp[r][c] == 0) {
                tmp[r][c] = 1;
                q.push({r, c});
            }
        }
        ans++;
    }
    return (n+2)*(n+2) - ans;
}
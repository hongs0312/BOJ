/*
18111
마인크래프트
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> blocks;
vector<long long> sum;

long long get_sum(int start, int end);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int n, m, b;
    cin >> n >> m >> b;
    blocks.resize(257);

    int input;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input;

            blocks[input]++;
        }
    }
    
    sum.resize(258);

    for(int i = 0; i < 257; i++) {
        sum[i+1] = sum[i] + blocks[i];
    }
    
    int lowest = 0, highest = 256;
    for(; lowest < highest; lowest++) {
        if(blocks[lowest] != 0)
            break;
    }
    for(; highest > lowest; highest--) {
        if(blocks[highest] != 0)
            break;
    }

    //[0] == b and [1] == time
    long long go_up[257][2] = {0}, go_down[257][2] = {0};
    for(int i = lowest; i < highest; i++) {
        go_up[i+1][0] = go_up[i][0] - get_sum(lowest, i);
        go_up[i+1][1] = go_up[i][1] + get_sum(lowest, i);
    }
    for(int i = highest; i > lowest; i--) {
        go_down[i-1][0] = go_down[i][0] + get_sum(i, highest);
        go_down[i-1][1] = go_down[i][1] + get_sum(i, highest)*2;
    }

    long long min_time = 0x7fffffffffff, ans_height;
    for(int i = highest; i >= lowest; i--) {
        if(go_up[i][0]+go_down[i][0]+b >= 0) {
            if(go_up[i][1]+go_down[i][1] < min_time) {
                min_time = go_up[i][1] + go_down[i][1];
                ans_height = i;
            }
        }
    }

    cout << min_time << " " << ans_height;
    
    return 0;
}
long long get_sum(int start, int end) {
    return sum[end+1] - sum[start];
}
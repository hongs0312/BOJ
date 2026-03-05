/*
9576
책 나눠주기
*/
#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

bool can_distribute[MAX];
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b);
void init_arr();
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int r;
    cin >> r;

    int n, m;
    pair<int, int> input;
    while(r--) {
        init_arr();

        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> input.first >> input.second;
            
            v.push_back(input);
        }
        sort(v.begin(), v.end(), compare);

        int cur, count = 0;
        for(pair<int, int> element:v) {
            cur = element.first;
            for(; cur <= element.second; cur++) {
                if(can_distribute[cur] == true) {
                    can_distribute[cur] = false;
                    count++;

                    break;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}
void init_arr() {
    v.clear();

    for(int i = 0; i < MAX; i++) {
        can_distribute[i] = true;
    }
}
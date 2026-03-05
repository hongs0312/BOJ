/*
7568
덩치
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;

    vector <vector<int>> v, temp;
    vector<int> inp;
    inp.resize(3);

    for(int i = 0; i < n; i++) {
        cin >> inp[0] >> inp[1];
        inp[2] = i;

        v.push_back(inp);
    }

    temp = v;
    sort(temp.begin(), temp.end());

    for(int i = 0; i < n; i++) {
        int j = 0;
        //find v[i] in temp(sorted v)
        for(; j < n; j++) {
            if(temp[j][2] == i) {
                j++;
                break;
            }
        }

        int cnt = 1;
        //find bigger than v[i]
        for(; j < n; j++) {
            if(temp[j][0] > v[i][0] && temp[j][1] > v[i][1])
                cnt++;
        }

        cout << cnt << " ";
    }

    return 0;
}
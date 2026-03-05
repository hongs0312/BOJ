/*
10775
공항
*/

#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

bool gate[MAX];
int plane_count[MAX];

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int g, p;
    cin >> g >> p;

    int plane_num, docking, answer = 0;
    for(int i = 0; i < p; i++) {
        cin >> plane_num;
        docking = plane_num-plane_count[plane_num];

        for(; docking > 0; docking--) {
            if(gate[docking] == false) {
                gate[docking] = true;

                plane_count[plane_num]++;
                answer++;

                break;
            }
        }
        if(docking == 0) break;
    }

    cout << answer;

    return 0;
}
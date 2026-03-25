/*
2437
저울
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    int input;
    vector<int> weights;
    for(int i = 0; i < n; i++) {
        cin >> input;
        weights.push_back(input);
    }
    sort(weights.begin(), weights.end());

    int k = 0;
    for(int w:weights) {
        if(w > k+1) break;

        k += w;
    }

    cout << k+1;

    return 0;
}
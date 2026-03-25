/*
16496
큰 수 만들기
*/
#include <bits/stdc++.h>

using namespace std;


vector<string> nums;

bool cmp(string &a, string &b);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;

        nums.push_back(to_string(input));
    }
    sort(nums.begin(), nums.end(), cmp);

    if(nums[0] == "0")
        cout << 0;
    else {
        for(int i = 0; i < n; i++)
            cout << nums[i];
    }
    return 0;
}
bool cmp(string &a, string &b) {
    return a+b > b+a;
}
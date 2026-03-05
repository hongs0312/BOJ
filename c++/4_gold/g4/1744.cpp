/*
1744
수 묶기
*/
#include <bits/stdc++.h>

using namespace std;

int get_ans(vector<int> num);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> num(n);

    for(int i = 0; i < n; i++)
        cin >> num[i];

    sort(num.begin(), num.end());

    cout << get_ans(num);    

    return 0;
}
int get_ans(vector<int> num) {
    int n = num.size();
    int ans = 0, l = 0, r = n-1;
    while(true) {
        //if reach end, sums all last nums
        if(l+1 >= n) {
            if(l < n) ans += num[l];

            return ans;
        }

        if(num[l+1] > 0)
            break;

        ans += num[l]*num[l+1];

        l += 2;
    }
    while(true) {
        if(r-1 < 0) {
            if(r == 0) ans += num[r];

            return ans;
        }

        if(num[r-1] <= 1)
            break;

        ans += num[r]*num[r-1];

        r -= 2;
    }
    for(int i = l; i <= r; i++) 
        ans += num[i];

    return ans;
}
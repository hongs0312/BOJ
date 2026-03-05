/*
1541
잃어버린 괄호
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    string input;
    cin >> input;

    int n = 0;
    int neg_idx = 0; //the sopt where the first minus is
    string s_num;
    for(char c:input) {
        if(c == '+' || c == '-') {
            n++;

            if(c == '-' && neg_idx == 0)
                neg_idx = n;

            nums.push_back(stoi(s_num));
            s_num = "";

            continue;
        }
        s_num += c;
    }
    nums.push_back(stoi(s_num));

    int num;
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        num = nums[i];
        
        if(neg_idx != 0 && i >= neg_idx)
            num *= -1;

       sum += num;
    }  

    cout << sum;
    
    return 0;
}
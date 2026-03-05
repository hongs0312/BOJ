/*
3687
성냥개비
*/
#include <bits/stdc++.h>
#define MAX 101
#define INF 0xffffffffffffffff
using namespace std;

//number 1 2 3 4 5 6 7 8 9 0

//                0  1  2  3  4  5  6  7  8  9
int make_num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
unsigned long long dp[MAX]; //idx: the number of sticks I have

void print_max(int n);
void get_min(int n);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    //init list
    for(int i = 0; i < MAX; i++)
        dp[i] = INF;

    int n;
    cin >> n;

    int input;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }
    int max_i = *max_element(nums.begin(), nums.end());
    get_min(max_i);

    for(int i:nums) {
        cout << dp[i] << " ";
        print_max(i);
        cout << "\n";
    }

    return 0;
}
void print_max(int n) {
    while(n > 0) {
        if (n%2 == 1) {
            cout << 7;
            n -= 3;
        }
        else {
            cout << 1;
            n -= 2;
        }
    }
}
void get_min(int n) {
    unsigned long long int asign[] = {INF, INF, 1, 7, 4, 2, 0, 8};

    for(int i = 2; i < 8; i++) {
        dp[i] = asign[i];
    }
    dp[6] = 6; //because num can't start with 0

    //make min max num
    int temp, num;
    for(int i = 8; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            temp = i-make_num[j];

            if(temp > 0 && dp[temp] < INF) {
                dp[i] = min(dp[temp]*10+j, dp[i]);
            }
        }
    }
}
/*
1025
제곱수 찾기
*/
#include <bits/stdc++.h>
#define MAX 34000

using namespace std;

vector<bool> nums(MAX, true);
vector<int> prime;

vector<int> get_prime(vector<bool> v);
int main() {
    freopen("../../IO_files/in.txt", "r", stdin);
    freopen("../../IO_files/out.txt", "w", stdout);
    
    prime = get_prime(nums);

    int n, m;
    cin >> n >> m;
    vector<vector<int>>v;
    v.assign(n, vector<int>(m));

    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 1; j <= m; j++) {
            v[i][m-j] = input%10;
            input /= 10;
        }
    }



    return 0;
}
vector<int> get_prime(vector<bool> arr) {
    vector<int> p;

    arr[1] = false;

    int n = arr.size();
    for(int i = 1; i*i < n; i++)
        if(arr[i] == true)
            for(int j = 2*i; j < arr.size(); j += i)
                arr[j] = false;

    for(int i = 1; i < n; i++)
        if(arr[i] == true)
            p.push_back(i);

    return p;
}
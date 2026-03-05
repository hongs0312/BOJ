/*
1654
랜선 자르기
*/
#include <bits/stdc++.h>

using namespace std;

vector<long long> lines;

long long cut_count(vector<long long> v, long long cut_len);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int k, n;
    cin >> k >> n;

    lines.resize(k);
    for(int i = 0; i < k; i++)
        cin >> lines[i];
    
    sort(lines.begin(), lines.end());

    long long l = 0, r = lines[k-1]+1;
    long long mid, tmp;
    while (l < r) {
        mid = (l+r)/2;
        tmp = cut_count(lines, mid);

        // if cut count is bigger then goal -> get longer the cut length
        if(tmp >= n) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout << (l+r)/2 - 1;

    return 0;
}
long long cut_count(vector<long long> v, long long cut_len) {
    long long result = 0;

    for(auto a:v)
        result += a/cut_len;

    return result;
}
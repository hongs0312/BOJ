/*
1700
멀티탭 스케줄링
*/
#include <bits/stdc++.h>

using namespace std;

int find_n(int n, vector<int> v);
int find_plug_off(int idx, vector<int> multi_tap, vector<int> order);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    int n, k;
    cin >> n >> k; // n: the mumber of plugs k: the number of use
    vector<int> order;

    int input;
    for(int i = 0; i < k; i++) {
        cin >> input;
        order.push_back(input);
    }

    int plug_off, count = 0;
    vector<int> multi_tap;
    for(int i = 0; i < k; i++) {
        if(multi_tap.size() < n) {
            if(find_n(order[i], multi_tap) == -1) {
                multi_tap.push_back(order[i]);
            }
            else continue;
        }
        else {
            plug_off = find_plug_off(i, multi_tap, order);
            if(plug_off != -1) {
                multi_tap[plug_off] = order[i];
                count++;
            }
        }
    }
    cout<<count;
    
    return 0;
}
int find_n(int n, vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == n)
            return i;
    }
    return -1;
}
int find_plug_off(int idx, vector<int> multi_tap, vector<int> order) {
    int result = 0, max_dis = 0, distance;

    for(int i = 0; i < multi_tap.size(); i++) {
        if(multi_tap[i] == order[idx])
            return -1;
        
        distance = 0;
        for(int j = idx + 1; j < order.size(); j++) {
            if(order[j] == multi_tap[i])
                break;
            distance++;
        }
        if(distance > max_dis) {
            max_dis = distance;
            result = i;
        }
    }
    return result;
}
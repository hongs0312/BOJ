/*
오아시스 재결합
*/
#include <bits/stdc++.h>

using namespace std;

stack<pair<long long, long long>> s;
long long ans;
int main(){
    ios::sync_with_stdio(false);
    
    int n, tmp;
    cin >> n;

    long long input;
    for(int i = 0; i < n; i++){
        cin >> input;
        while(!s.empty() && s.top().first < input){
            ans += s.top().second;
            s.pop();
        }
        
        if(s.empty())
            s.push({input, 1});
        else if(s.top().first == input){
            tmp = s.top().second;

            ans += tmp + (s.size() > 1);

            s.pop();
            s.push({input, tmp + 1});
        }
        else{
            ans++;
            s.push({input, 1});
        }
    }
    cout << ans;

    return 0;
}
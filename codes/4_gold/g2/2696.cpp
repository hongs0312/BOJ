/*
2696
중앙값 구하기
*/
#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

class Mid_heap {
private:
    priority_queue<long long> l, r;
public:
    void init() {
        l = priority_queue<long long>();
        r = priority_queue<long long>();
    }
    void push(long long x) {
        long long tmp;
        if(l.size() == r.size()) {
            if(r.size() > 0 && -r.top() < x) {
                tmp = -r.top();
                
                r.pop();
                r.push(-x);

                x = tmp;
            }
            l.push(x);
        }
        else {
            if(l.top() > x) {
                tmp = l.top();
                
                l.pop();
                l.push(x);
                
                x = tmp;
            }
            r.push(-x);
        }
        
    }
    long long mid() {
        return l.top();
    }
};

Mid_heap pq;
int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif
    
    fast_io();

    int t, m;
    cin >> t;
    
    long long input;
    while(t-- > 0) {
        pq.init();

        cin >> m;
        cout << (m+1)/2;

        for(int i = 0; i < m; i++) {
            cin >> input;

            pq.push(input);

            if(i%20 == 0) cout << "\n";

            if(i%2 == 0) cout << pq.mid() << " ";

        }
        cout << "\n";
    }
    return 0;
}
/*
3679
단순 다각형
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pV; //place vector
typedef struct element{
    int idx;
    pV point;
}element;

pV pivot;

pV vec_process(pV a, pV b, int k); //get a+kb
ll get_outer(pV a, pV b);
ll get_norm_sq(pV x);
ll get_dist_sq(pV a, pV b);

int CCW(pV p1, pV p2, pV p3);
vector<element> get_convex(vector<element> v);
int main() {
    // freopen("../../IO_files/in.txt", "r", stdin);
    // freopen("../../IO_files/out.txt", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    cin >> r;
    while(r-- > 0) {
        int n;
        cin >> n;
        
        vector<element> v(n);
        for(int i = 0; i < n; i++) {
            v[i].idx = i;
            cin >> v[i].point.first >> v[i].point.second;
        }
        
        vector<element> poligon = get_convex(v);
        for(element e:poligon)
            cout << e.idx << " ";
        cout << "\n";
    }
    return 0;
}
bool compare(element a, element b) {
    int result = CCW(pivot, a.point, b.point);

    if(result == 0) {
        ll distance_a = get_dist_sq(a.point, pivot);
        ll distance_b = get_dist_sq(b.point, pivot);

        return distance_a < distance_b;
    }

    return result > 0;
}
pV vec_process(pV a, pV b, int k) {
    pV result;

    result.first = a.first + k*b.first;
    result.second = a.second + k*b.second;

    return result;
}
ll get_outer(pV a, pV b) {
    return a.first*b.second - a.second*b.first;
}
ll get_norm_sq(pV x) {
    return x.first*x.first + x.second*x.second;
}
ll get_dist_sq(pV a, pV b) {
    return get_norm_sq(vec_process(a, b, -1));
}
int CCW(pV p1, pV p2, pV p3) {
    pV dir1 = vec_process(p1, p2, -1);
    pV dir2 = vec_process(p2, p3, -1);

    ll outer = get_outer(dir1, dir2);

    if(outer < 0)
        return -1;
    else if(outer > 0)
        return 1;
    else
        return 0;
}
vector<element> get_convex(vector<element> v) {
    int n = v.size();

    int idx = 0;
    pivot = v[0].point;
    for(int i = 1; i < n; i++) {
        if(v[i].point.second < pivot.second) {
            pivot = v[i].point;

            idx = i;
        }
        else if(v[i].point.second == pivot.second) {
            if(v[i].point.first < pivot.first) {
                pivot = v[i].point;

                idx = i;
            }
        }
    }
    v.erase(v.begin() + idx);
    sort(v.begin(), v.end(), compare);
    v.insert(v.begin(), {idx, pivot});

    vector<element> tmp;
    if(n > 2) {
        int cur = n-1;
        pV first = v[0].point, last = v[n-1].point;
        while(CCW(last, first, v[cur].point) == 0)
            tmp.push_back(v[cur--]);

        auto f = [](element a, element b) -> bool {
            return get_dist_sq(pivot, a.point) > get_dist_sq(pivot, b.point);
        };
        sort(tmp.begin(), tmp.end(), f);

        cur++;
        for(int i = 0; i < tmp.size(); i++)
            v[cur+i] = tmp[i];
    }
    return v;
}
/*
2049
가장 먼 두 점
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pV; //place vector

pV pivot;

pV vec_process(pV a, pV b, int k); //get a+kb
ll get_outer(pV a, pV b);
ll get_norm_sq(pV x);
ll get_dist_sq(pV a, pV b);

int CCW(pV p1, pV p2, pV p3);
vector<pV> get_convex(vector<pV> v);
ll rotating_callipus(vector<pV> convex);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pV> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    
    vector<pV> convex = get_convex(v);
    cout << rotating_callipus(convex);

    return 0;
}
bool compare(pV a, pV b) {
    int result = CCW(pivot, a, b);

    if(result == 0) {
        ll distance_a = get_dist_sq(a, pivot);
        ll distance_b = get_dist_sq(b, pivot);

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
vector<pV> get_convex(vector<pV> v) {
    int n = v.size();

    int idx = 0;
    pivot = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i].second < pivot.second) {
            pivot = v[i];

            idx = i;
        }
        else if(v[i].second == pivot.second) {
            if(v[i].first < pivot.first) {
                pivot = v[i];

                idx = i;
            }
        }
    }
    v.erase(v.begin() + idx);
    sort(v.begin(), v.end(), compare);
    v.insert(v.begin(), pivot);

    vector<pV> result;
    result.push_back(v[0]);
    result.push_back(v[1]);

    int top = 1;
    for(int i = 2; i < n; i++) {
        while(top > 0 && CCW(result[top-1], result[top], v[i]) <= 0) {
            result.pop_back();
            top--;
        }
        result.push_back(v[i]);
        top++;
    }
    return result;
}
ll rotating_callipus(vector<pV> convex) {
    int n = convex.size();

    int f1 = 0, f2 = n-1; //fairest two points
    ll max_dist = get_dist_sq(convex[f1], convex[f2]);

    int p1 = 0, p2 = 1, n_p1, n_p2;
    ll dist, outer;
    pV dir1, dir2;
    for(; p1 < n; p1++) {
        n_p1 = (p1+1)%n;

        //find opposite point
        while(true) {
            n_p2 = (p2+1)%n;

            dir1 = vec_process(convex[n_p1], convex[p1], -1);
            dir2 = vec_process(convex[n_p2], convex[p2], -1);
            outer = get_outer(dir1, dir2);

            if(outer <= 0) break;

            p2 = n_p2;
        }
        //get distance of two points
        dist = get_dist_sq(convex[p1], convex[p2]);
        if(dist > max_dist) {
            max_dist = dist;
            
            f1 = p1;
            f2 = p2;
        }
    }
    return max_dist;
}
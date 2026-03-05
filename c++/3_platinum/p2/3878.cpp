/*
3878
점 분리
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pV; //place vector
typedef vector<pV> v_pV;

pV pivot;

pV vec_process(pV a, pV b, int k); //get a+kb
ll get_outer(pV a, pV b);
double get_norm(pV x);
double get_dist(pV a, pV b);

int CCW(pV &p1, pV &p2, pV &p3);
v_pV get_convex(v_pV&v);
bool is_intersect(pV b0, pV b1, pV w0, pV w1);
bool is_in_convex(v_pV &v, pV &p);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    cin >> r;
    while(r-- > 0) {
        int n, m;
        cin >> n >> m;

        v_pV black(n), white(m);
        for(int i = 0; i < n; i++)
            cin >> black[i].first >> black[i].second;

        for(int i = 0; i < m; i++)
            cin >> white[i].first >> white[i].second;

        v_pV b_conv = get_convex(black);
        v_pV w_conv = get_convex(white);
        
        bool flag = true;

        n = b_conv.size();
        m = w_conv.size();

        for(int i = 0; i < n && flag == true; i++)
            if(is_in_convex(w_conv, b_conv[i]))
                flag = false;

        for(int i = 0; i < m && flag == true; i++)
            if(is_in_convex(b_conv, w_conv[i]))
                flag = false;

        for(int i = 0; i < n && flag == true; i++) {
            for(int j = 0; j < m && flag == true; j++) {
                if(is_intersect(b_conv[i], b_conv[(i+1)%n], w_conv[j], w_conv[(j+1)%m]) == true)
                    flag = false;
            }
        }
        if(flag == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
bool compare(pV &a, pV &b) {
    int result = CCW(pivot, a, b);

    if(result == 0) {
        double distance_a = get_dist(a, pivot);
        double distance_b = get_dist(b, pivot);

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
double get_norm(pV x) {
    return sqrt(x.first*x.first + x.second*x.second);
}
double get_dist(pV a, pV b) {
    return get_norm(vec_process(a, b, -1));
}
int CCW(pV &p1, pV &p2, pV &p3) {
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
v_pV get_convex(v_pV &v) {
    int n = v.size();

    if(n == 1) return {v[0]};

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

    v_pV result;
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
bool is_intersect(pV b0, pV b1, pV w0, pV w1) {
    int tmp1 = CCW(b0, b1, w0)*CCW(b0, b1, w1);
    int tmp2 = CCW(w0, w1, b0)*CCW(w0, w1, b1);

    if(tmp1 == 0 && tmp2 == 0) {
        if (b0 > b1) swap(b0, b1);
        if (w0 > w1) swap(w0, w1);

        return w0 <= b1 && b0 <= w1;
    }
    return tmp1 <= 0 && tmp2 <= 0;
}
bool is_in_convex(v_pV &v, pV &p) {
    int n = v.size();

    if(n <= 2) return false;

    pV anchor = v[0];

    if(CCW(anchor, v[1], p) < 0) return false;
    if(CCW(anchor, v[n-1], p) > 0) return false;
    
    int tmp, l = 1, r = n-1, m;
    while(l + 1 < r) {
        m = (l+r) >> 1;

        tmp = CCW(anchor, v[m], p);
        if(tmp > 0) l = m;
        else r = m;
    }
    return CCW(v[l], p, v[l+1]) <= 0;
}
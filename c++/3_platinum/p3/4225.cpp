/*
4225
쓰레기 슈트
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<double, double> pV; //place vector

pV pivot;

pV vec_process(pV a, pV b, double k); //get a+kb
double get_inner(pV a, pV b);
double get_outer(pV a, pV b);
double get_norm(pV x);
double get_dist(pV a, pV b);

int CCW(pV p1, pV p2, pV p3);
vector<pV> get_convex(vector<pV> v);
double rotating_callipus(vector<pV> convex);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 1;
    while (true) {
        int n;
        cin >> n;

        if(n == 0) break;
        
        vector<pV> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        
        vector<pV> convex = get_convex(v);
        printf("Case %d: %.2lf\n",count++, ceil(rotating_callipus(convex)*100)/100);
    }

    return 0;
}
bool compare(pV a, pV b) {
    int result = CCW(pivot, a, b);

    if(result == 0) {
        double distance_a = get_dist(a, pivot);
        double distance_b = get_dist(b, pivot);

        return distance_a < distance_b;
    }

    return result > 0;
}
pV vec_process(pV a, pV b, double k) {
    pV result;

    result.first = a.first + k*b.first;
    result.second = a.second + k*b.second;

    return result;
}
double get_inner(pV a, pV b) {
    return a.first*b.first + a.second*b.second;
}
double get_outer(pV a, pV b) {
    return a.first*b.second - a.second*b.first;
}
double get_norm(pV x) {
    return sqrt(x.first*x.first + x.second*x.second);
}
double get_dist(pV a, pV b) {
    return get_norm(vec_process(a, b, -1));
}
int CCW(pV p1, pV p2, pV p3) {
    pV dir1 = vec_process(p1, p2, -1);
    pV dir2 = vec_process(p2, p3, -1);

    double outer = get_outer(dir1, dir2);

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
double rotating_callipus(vector<pV> convex) {
    int n = convex.size();

    double min_dist = 30000;

    int p1 = 0, p2 = 1, n_p1, n_p2;
    double dist, outer;
    pV dir1, dir2;
    for(; p1 < n; p1++) {
        n_p1 = (p1+1)%n;
        dir1 = vec_process(convex[n_p1], convex[p1], -1);

        //find opposite point
        while(true) {
            n_p2 = (p2+1)%n;

            dir2 = vec_process(convex[n_p2], convex[p2], -1);
            outer = get_outer(dir1, dir2);

            if(outer <= 0) break;

            p2 = n_p2;
        }
        pV dir_vec = vec_process({0, 0}, dir1, 1/get_norm(dir1));
        pV p1p2 = vec_process(convex[p2], convex[p1], -1);
        pV tmp = vec_process(convex[p1], dir_vec, get_inner(dir_vec, p1p2));

        //get distance of two points
        dist = get_dist(convex[p2], tmp);
        if(dist < min_dist) {
            min_dist = dist;
        }
    }
    return min_dist;
}
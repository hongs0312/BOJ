/*
9240
로버트 후드
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int y;
}p_vec;

p_vec pivot;

bool compare(p_vec a, p_vec b);
p_vec get_salar_mult(double k, p_vec a);
p_vec get_add(p_vec a, p_vec b);
p_vec get_sub(p_vec a, p_vec b);
int get_outer(p_vec a, p_vec b);
int ccw(p_vec p, p_vec a, p_vec b);
double get_norm(p_vec a);
double get_distance(p_vec a, p_vec b);

vector<p_vec> get_convex(vector<p_vec> arrows);
double get_score(vector<p_vec> convex);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;

    p_vec input;
    vector<p_vec> arrows; 
    for(int i = 0; i < n; i++) {
        cin >> input.x >> input.y;

        arrows.push_back(input);
    }

    vector<p_vec> convex;
    convex = get_convex(arrows);

    double score;
    score = get_score(convex);

    printf("%lf", score);

    return 0;
}
bool compare(p_vec a, p_vec b) {
    int result = ccw(pivot, a, b);

    if(result == 0) {
        double distance_a = get_distance(a, pivot);
        double distance_b = get_distance(b, pivot);

        return distance_a < distance_b;
    }

    return result > 0;
}
p_vec get_salar_mult(double k, p_vec a) {
    p_vec result;
    
    result.x = k * a.x;
    result.y = k * a.y;

    return result;
}
p_vec get_add(p_vec a, p_vec b) {
    p_vec result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}
p_vec get_sub(p_vec a, p_vec b) {
    p_vec result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}
int get_outer(p_vec a, p_vec b) {
    int result;

    result = a.x*b.y - a.y*b.x;

    return result;
}
int ccw(p_vec p, p_vec a, p_vec b) {
    p_vec dir_a = get_sub(a, p);
    p_vec dir_b = get_sub(b, p);

    int outer = get_outer(dir_a, dir_b);

    if(outer > 0) {
        return 1;
    }
    else if(outer < 0) {
        return -1;
    }
    else {
        return 0;
    }
}
double get_norm(p_vec a) {
    double result;

    result = sqrt(pow(a.x, 2) + pow(a.y, 2));

    return result;
}
double get_distance(p_vec a, p_vec b) {
    double result;

    result = get_norm(get_sub(a, b));

    return result;
}

vector<p_vec> get_convex(vector<p_vec> arrows) {
    int n = arrows.size();

    int idx = 0;
    pivot = arrows[0];
    for(int i = 1; i < n; i++) {
        if(arrows[i].y < pivot.y) {
            pivot = arrows[i];

            idx = i;
        }
        else if(arrows[i].y == pivot.y) {
            if(arrows[i].x < pivot.x) {
                pivot = arrows[i];

                idx = i;
            }
        }
    }
    arrows.erase(arrows.begin() + idx);

    //sort with counterclockwise
    sort(arrows.begin(), arrows.end(), compare);
    arrows.insert(arrows.begin(), pivot);

    //convexhull result
    vector<p_vec> result;
    result.push_back(arrows[0]);
    result.push_back(arrows[1]);
    
    p_vec dir, temp;
    double outer;
    int top = 1;
    idx = 2;
    for(int i = 2; i < n; i++) {
        while(top > 1 && ccw(result[top-1], result[top], arrows[i]) <= 0) {
            result.pop_back();
            top--;
        }
        result.push_back(arrows[i]);
        top++;
    }
    
    return result;
}
double get_score(vector<p_vec> convex) {
    int n = convex.size();

    double score = 0;
    double distance;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            distance = get_distance(convex[i], convex[j]);

            if(distance > score) {
                score = distance;
            }
        }
    }

    return score;
}
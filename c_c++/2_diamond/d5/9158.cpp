/*
9158
Super Star
*/
#include <bits/stdc++.h>

#define MAX_RUN 20000
#define ERROR 0.0001
#define UPDATE_RATE 0.999

using namespace std;

typedef struct {
    double first;
    double second;
    double third;
}p_vec;

typedef struct {
    p_vec center;
    double rad;
}answer;

vector<p_vec> points;

p_vec get_add(p_vec a, p_vec b);
p_vec get_sub(p_vec a, p_vec b);
p_vec get_scalar_mult(double k, p_vec x);
double get_amount(p_vec x);
double get_distance(p_vec a, p_vec b);
p_vec get_farhest_point(p_vec x);
answer solve(int n);
int main() {
    freopen("IO_files/in.txt", "r", stdin);
    freopen("IO_files/out.txt", "w", stdout);

    int n;
    cin >> n;

    answer ans;
    ans = solve(n);
    printf("%.5lf\n", ans.rad);

    return 0;
}
//get a+b (vector)
p_vec get_add(p_vec a, p_vec b) {
    p_vec result;

    result.first = a.first + b.first;
    result.second = a.second + b.second;
    result.third = a.third + b.third;

    return result;
}
//get a-b (vector)
p_vec get_sub(p_vec a, p_vec b) {
    p_vec result;
    
    result.first = a.first - b.first;
    result.second = a.second - b.second;
    result.third = a.third - b.third;

    return result;
}
//get kx (k : scalar x: vector)
p_vec get_scalar_mult(double k, p_vec x) {
    p_vec result;

    result.first = k * x.first;
    result.second = k * x.second;
    result.third = k * x.third;

    return result;
}
//get |x|
double get_amount(p_vec x) {
    return sqrt(pow(x.first, 2) + pow(x.second, 2) + pow(x.third, 2));
}
//getting distance between two points
double get_distance(p_vec a, p_vec b) {
    p_vec sub = get_sub(a, b);
    
    return get_amount(sub);
}
//get farhest point
p_vec get_farhest_point(p_vec x) {
    double farhest_dis = 0;
    p_vec farhest_point;

    double dis; 
    for(p_vec p:points) {
        dis = get_distance(x, p);

        if(dis > farhest_dis) {
            farhest_point = p;
            farhest_dis = dis;
        }
    }
    return farhest_point;
}
answer solve(int n) {
    points.clear();

    p_vec input;
    for(int i = 0; i < n; i++) {
        cin >> input.first >> input.second >> input.third;

        points.push_back(input);
    }

    p_vec cur_point = {0, 0, 0};
    for(int i = 0; i < n; i++) {
        cur_point.first += points[i].first;
        cur_point.second += points[i].second;
        cur_point.third += points[i].third;
    }

    cur_point.first /= n;
    cur_point.second /= n;
    cur_point.third /= n;

    answer result;

    p_vec farhest_point, temp;
    double learning_rate = 0.1;
    for(int i = 0; i < MAX_RUN; i++) {
        farhest_point = get_farhest_point(cur_point);

        temp = get_sub(farhest_point, cur_point);
        temp = get_scalar_mult(learning_rate, temp);
        cur_point = get_add(cur_point, temp);

        learning_rate *= UPDATE_RATE;
    }

    if(abs(cur_point.first) < ERROR && cur_point.first < 0)
        cur_point.first *= -1;
    
    if(abs(cur_point.second) < ERROR && cur_point.second < 0)
        cur_point.second *= -1;

    if(abs(cur_point.third) < ERROR && cur_point.third < 0)
        cur_point.third *= -1;

    result.center = cur_point;
    result.rad = get_distance(cur_point, get_farhest_point(cur_point));

    return result;
}
/*
2626
헬기 착륙장

** 경사하강법으로 풀었음 (어케 이게 되노 ㅋㅋ) **
*/
#include <bits/stdc++.h>

#define MAX_RUN 20000
#define UPDATE_RATE 0.999

using namespace std;

typedef pair<double, double> p_vec;

vector<p_vec> points;

p_vec get_add(p_vec a, p_vec b);
p_vec get_sub(p_vec a, p_vec b);
p_vec get_scalar_mult(double k, p_vec x);
double get_amount(p_vec x);
double get_distance(p_vec a, p_vec b);
p_vec get_farhest_point(p_vec x);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;

    p_vec input;
    for(int i = 0; i < n; i++) {
        cin >> input.first >> input.second;

        points.push_back(input);
    }

    p_vec cur_point = {0, 0};
    for(int i = 0; i < n; i++) {
        cur_point.first += points[i].first;
        cur_point.second += points[i].second;
    }

    cur_point.first /= n;
    cur_point.second /= n;

    p_vec farhest_point, temp;
    double learning_rate = 0.1;
    for(int i = 0; i < MAX_RUN; i++) {
        farhest_point = get_farhest_point(cur_point);

        temp = get_sub(farhest_point, cur_point);
        temp = get_scalar_mult(learning_rate, temp);
        cur_point = get_add(cur_point, temp);

        learning_rate *= UPDATE_RATE;
    }

    if(abs(cur_point.first) < 0.001 && cur_point.first < 0)
        cur_point.first *= -1;
    
    if(abs(cur_point.second) < 0.001 && cur_point.second < 0)
        cur_point.second *= -1;
    
    // printf("%.3lf %.3lf\n", cur_point.first, cur_point.second);
    printf("%.2lf", round(get_distance(cur_point, get_farhest_point(cur_point))*200)/100.0);

    return 0;
}
//get a+b (vector)
p_vec get_add(p_vec a, p_vec b) {
    p_vec result;

    result.first = a.first + b.first;
    result.second = a.second + b.second;

    return result;
}
//get a-b (vector)
p_vec get_sub(p_vec a, p_vec b) {
    p_vec result;
    
    result.first = a.first - b.first;
    result.second = a.second - b.second;

    return result;
}
//get kx (k : scalar x: vector)
p_vec get_scalar_mult(double k, p_vec x) {
    p_vec result;

    result.first = k * x.first;
    result.second = k * x.second;

    return result;
}
//get |x|
double get_amount(p_vec x) {
    return sqrt(pow(x.first, 2) + pow(x.second, 2));
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
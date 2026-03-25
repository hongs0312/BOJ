/*
10531
Golf Bot
*/
#include <bits/stdc++.h>

#define MAX 200001

using namespace std;

typedef vector<int> v_int;
typedef complex<double> cpx;
typedef vector<cpx> v_cpx;

const double PI = acos(-1);

v_cpx multiply(v_cpx a, v_cpx b);
bool find_can_reach(v_int &v, int value, int l, int r);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int input;
    v_cpx a(MAX, 0), b(MAX, 0);
    a[0] = b[0] = {1, 0};
    for(int i = 0; i < n; i++) {
        cin >> input;

        a[input] = b[input] = {1, 0};
    }
    v_cpx c = multiply(a, b);

    v_int can_reach;
    for(int i = 0; i < c.size(); i++) {
        if(c[i].real() == 0) continue;

        can_reach.push_back(i);
    }

    int m;
    cin >> m;

    int dist, ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> dist;

        if(find_can_reach(can_reach, dist, 0, can_reach.size()-1))
            ans += 1;
    }
    cout << ans;

    return 0;
}
//f(w)를 fft를 이용해 구하기
void FFT(v_cpx &f, bool inv) {
    int n = (int) f.size();
    //prep f classifing
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(f[i], f[j]);
    }
    //do fft
    for (int step = 1; step < n; step <<= 1) { //decide step
        double x = inv ? PI / step : -PI / step;

        cpx w = {cos(x), sin(x)};
        
        for (int start = 0; start < n; start += step << 1) { //decide start point
            cpx wp = {1, 0};
            for (int i = 0; i < step; i++) {
                cpx tmp = f[start + step + i] * wp;         // get f_odd
                
                f[start + step + i] = f[start + i] - tmp;   //f(-w) = f_even(w^2) - w*f_odd(w^2)
                f[start + i] = f[start + i] + tmp;          //f(w) = f_even(w^2) + w*f_odd(w^2)
                
                wp *= w;
            }
        }
    }
    if(inv == true) {
        for(int i = 0; i < n; i++) {
            f[i] /= cpx(n, 0);
            f[i] = cpx(round(f[i].real()), round(f[i].imag()));
        }
    }
}
void prep_v(v_cpx &a, v_cpx &b) {
    int n = a.size();

    a.resize(2*n);
    for(int i = 0; i < n; i++)
        a[i+n] = a[i];

    reverse(b.begin(), b.end());
}
v_cpx multiply(v_cpx a, v_cpx b){
    int l = max(a.size(), b.size());
    
    int n = 1;
    while(n < l) n = n << 1;
    n = n << 1;

    a.resize(n);
    b.resize(n);

    FFT(a, false);
    FFT(b, false);

    v_cpx c(n);
    for(int i = 0; i < n; i++) 
        c[i] = a[i]*b[i];

    FFT(c, true);
    
    return c;
}
bool find_can_reach(v_int &v, int value, int l, int r){
    int m;
    while(l <= r) {
        m = (l+r) >> 1;

        if(v[m] < value) l = m+1;
        else if(v[m] > value) r = m-1;
        else return true;
    }

    return false;
}
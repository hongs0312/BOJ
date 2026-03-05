/*
1067
이동
*/
#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cpx;
typedef vector<cpx> v_cpx;

const double PI = acos(-1);

v_cpx multiply(v_cpx a, v_cpx b);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    double input;
    v_cpx a(n, 0), b(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> input;
        a[i] = {input, 0};
    }
    for(int i = 0; i < n; i++) {
        cin >> input;
        b[i] = {input, 0};
    }
    v_cpx c = multiply(a, b);

    int ans = 0;
    for(int i = 0; i < c.size(); i++)
        ans = max((int)(c[i].real()), ans);

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
    reverse(a.begin(), a.end());

    int n = b.size();

    b.resize(2*n);
    for(int i = 0; i < n; i++)
        b[i+n] = b[i];
}
v_cpx multiply(v_cpx a, v_cpx b){
    prep_v(a, b);

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
/*
FFT 알고리즘 구현체
*/
#include <bits/stdc++.h>

using namespace std;

typedef complex<long double> cpx;
typedef vector<cpx> v_cpx;

const long double PI = acos(-1);

v_cpx multiply(v_cpx a, v_cpx b);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

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
        long double x = inv ? PI / step : -PI / step;

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
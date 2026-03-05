/*
11385
씽크스몰
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<long double> cpx;
typedef vector<cpx> v_cpx;
typedef vector<ll> v_ll;

const long double PI = acos(-1);

v_cpx multiply(v_cpx a, v_cpx b);
v_ll solve(v_ll &a, v_ll &b);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<v_ll> xy(4, v_ll(max(n+1, m+1))), result(4);

    int input;
    for(int i = 0; i <= n; i++) {
        cin >> input;

        xy[0][i] = input >> 10;
        xy[1][i] = input & 0x3ff;
    }
    for(int i = 0; i <= m; i++) {
        cin >> input;

        xy[2][i] = input >> 10;
        xy[3][i] = input & 0x3ff;
    }

    result[0] = solve(xy[0], xy[2]);
    result[1] = solve(xy[0], xy[3]);
    result[2] = solve(xy[1], xy[2]);
    result[3] = solve(xy[1], xy[3]);

    ll ans = 0;
    for(int i = 0; i <= n+m; i++)
        ans ^= (result[0][i] << 20) + ((result[1][i]+result[2][i]) << 10) + result[3][i];

    cout << ans;

    return 0;
}
v_ll solve(v_ll &x, v_ll &y) {
    int n = x.size();
    int m = y.size();

    v_cpx a(n), b(m), c;
    for(int i = 0; i < n; i++)
        a[i] = {(long double)x[i], 0};

    for(int i = 0; i < m; i++)
        b[i] = {(long double)y[i], 0};

    c = multiply(a, b);

    int l = c.size();
    v_ll result(l);
    for(int i = 0; i < l; i++)
        result[i] = (ll)(c[i].real());

    return result;
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
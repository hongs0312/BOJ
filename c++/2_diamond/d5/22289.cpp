/*
22289
큰 수 곱셈 (3)
*/
#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cpx;
typedef vector<cpx> v_cpx;

const double PI = acos(-1);

string multiply(string a, string b);
int main() {
    #ifdef SH_LOCAL
    freopen("c++/0_IO_files/in.txt", "r", stdin);
    freopen("c++/0_IO_files/out.txt", "w", stdout);
    #endif

    string a, b;
    cin >> a >> b;

    cout << multiply(a, b);

    return 0;
}
void str_to_v_cpx(v_cpx &v, string &s) {
    int diff = v.size() - s.length();

    for(int i = 0; i < s.length(); i++)
        v[diff+i] = {(double)(s[i]-'0'), 0};
}
string v_cpx_to_str(v_cpx &v) {
    int n = v.size();
    vector<int> carry(n+1, 0);

    reverse(v.begin(), v.end());

    string str = "";

    int tmp;
    for(int i = 1; i < n; i++) {
        tmp = (int)(v[i].real()) + carry[i];
        
        carry[i+1] = tmp/10;
        str += tmp%10+'0';
    }

    while(carry[n] > 0) {
        str += carry[n]%10+'0';

        carry[n] /= 10;
    }

    int i = str.length() - 1;
    
    //discard 0
    while(str[i] == '0') i--;

    string ans = str.substr(0, i+1);
    reverse(ans.begin(), ans.end());
    
    if(ans == "")
        return "0";
    else
        return ans;
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
string multiply(string a, string b){
    int l = max(a.length(), b.length());

    int n = 1;
    while(n < l) n = n << 1;
    n = n << 1;

    cpx w(cos(2*PI/n), sin(2*PI/n));

    v_cpx a_cpx(n, 0), b_cpx(n, 0), c_cpx(n, 0);

    str_to_v_cpx(a_cpx, a); 
    str_to_v_cpx(b_cpx, b);

    FFT(a_cpx, false);
    FFT(b_cpx, false);

    for(int i = 0; i < n; i++) 
        c_cpx[i] = a_cpx[i]*b_cpx[i];

    FFT(c_cpx, true);
    
    return v_cpx_to_str(c_cpx);
}
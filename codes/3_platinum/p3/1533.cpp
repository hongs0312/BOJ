/*
1533
길의 개수
*/
#include <bits/stdc++.h>
#define MOD 1000003

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix adj;

matrix get_adj(matrix v);
matrix matrix_pow(matrix v, ll n);
int main() {
    // freopen("../../0_IO_files/in.txt", "r", stdin);
    // freopen("../../0_IO_files/out.txt", "w", stdout);

    ll n, s, e, t;
    cin >> n >> s >> e >> t;

    matrix v;
    v.assign(n, vector<ll>(n, 0));

    ll input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < n; j++) {
            v[i][n-j-1] = input%10;
            input /= 10;
        }
    }

    matrix result = matrix_pow(get_adj(v), t);
    cout << result[5*(s-1)][5*(e-1)];
    
    return 0;
}
matrix get_adj(matrix v) {
    int n = v.size();
    
    matrix result;
    result.assign(5*n, vector<ll>(5*n, 0));

    int r, c;
    for(int i = 0; i < n; i++) {
        r = 5*i+1; c = 5*i;
        for(int j = 0; j < 4; j++) {
            result[r][c] = 1;
            r++; c++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] > 0) {
                c = 5*j + v[i][j] - 1;
                result[5*i][c]++;
            }
        }
    }
    return result;
}
matrix matrix_mult (matrix a, matrix b) {
    matrix result;

    int n = a.size();
    int m = b[0].size();

    result.assign(n, vector<ll>(m, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < a[0].size(); k++)
                result[i][j] = (result[i][j] + ((ll)(a[i][k]*b[k][j])%MOD))%MOD;
        }
    }
    return result;
}
matrix matrix_pow(matrix v, ll n) {
    if(n == 1) return v;

    matrix result = matrix_pow(v, n/2);

    result = matrix_mult(result, result);
    if(n%2 == 1)
        result = matrix_mult(result, v);

    return result;
}
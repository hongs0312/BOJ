#include <bits/stdc++.h>

using namespace std;

template <typename T> 
class Matrix {
private:
    int n, m;
    vector<vector<T>> matrix;
public:
    Matrix(int n, int m) {
        this->n = n; this->m = m;
        this->matrix.assign(n, vector<T>(m, 0));
    }
    pair<int, int> size() { return {this->n, this->m}; }
    vector<T>& operator[](int index) { return matrix[index]; }

    void print() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << matrix[i][j] << " ";
            
            cout << "\n";
        }
    }
    Matrix<T>& operator=(const Matrix<T> &ref) {
        if(this == &ref) return *this;

        this->n = ref.n;
        this->m = ref.m;
        this->matrix = ref.matrix;

        return *this;
    }
    Matrix<T> operator+(const Matrix<T> &ref) {
        if(this->n != ref.n || this->m != ref.m) throw "Can not operate each!";

        Matrix<T> ret(this->n, this->m);
        for(int i = 0; i < this->n; i++) {
            for(int j = 0; j < this->m; j++) {
                ret.matrix[i][j] = this->matrix[i][j] + ref.matrix[i][j];
            }
        }
        return ret;
    }
    Matrix<T> operator*(const Matrix<T> &ref) {
        if(this->m != ref.n) throw "Can not product each!";

        Matrix<T> ret(this->n, ref.m);
        for(int i = 0; i < ret.n; i++) {
            for(int j = 0; j < ret.m; j++) {
                for(int k = 0; k < this->m; k++)
                    ret.matrix[i][j] += this->matrix[i][k]*ref.matrix[k][j];
            }
        }
        return ret;
    }
    Matrix<T> operator*(const T &scalar) const {
        Matrix<T> ret(n, m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ret[i][j] = matrix[i][j] * scalar;
        return ret;
    }
    friend Matrix<T> operator*(const T& scalar, const Matrix<T>& mat) {
        return mat * scalar; // 내부의 Matrix * T 연산 호출
    }
    Matrix<T> transpose() {
        Matrix ret(m, n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                ret[i][j] = matrix[j][i];
        }
        return ret;
    }
    static Matrix<T> identity(int size) {
        Matrix ret(size, size);

        for(int i = 0; i < size; i++)
            ret[i][i] = 1;

        return ret;
    }
};

int main() {
    #ifdef SH_LOCAL
    freopen("codes/0_IO_files/in.txt", "r", stdin);
    freopen("codes/0_IO_files/out.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    Matrix<int> a(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    a.print();

    Matrix<int> b = a.transpose();
    b.print();

    Matrix<int> c = a*b;
    c.print();
    return 0;
}
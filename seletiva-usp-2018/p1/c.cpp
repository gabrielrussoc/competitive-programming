#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

struct Matrix {
    int n;
    vector<vector<ll>> m;
    Matrix() {}
    Matrix(int _n, bool id = false) {
        n = _n;
        m = vector<vector<ll>>(n);
        for(int i = 0; i < n; i++) { 
            m[i] = vector<ll>(n);
            fill(m[i].begin(), m[i].end(), 0);
            m[i][i] = id;
        }
    }
    Matrix operator*(const Matrix &o) {
        Matrix ret(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    ret.m[i][j] = (ret.m[i][j] + m[i][k] * o.m[k][j]) % MOD;
        return ret;
    }
};

ostream& operator<<(ostream &out, const Matrix &A) {
    for(int i = 0; i < A.n; i++) {
        for(int j = 0; j < A.n; j++)
            out << A.m[i][j] << ' ';
        out << endl;
    }
    return out;
}

Matrix operator^(Matrix A, ll e) {
    Matrix ret(A.n, true);
    while(e) {
        if(e&1) ret = ret * A;
        A = A * A;
        e /= 2;
    }
    return ret;
}

vector<ll> operator*(const Matrix &A, const vector<ll> &b) {
    int n = A.n;
    vector<ll> ret(n);
    for(int i = 0; i < n; i++) {
        ret[i] = 0;
        for(int j = 0; j < n; j++) 
            ret[i] = (ret[i] + A.m[i][j] * b[j]) % MOD;
    }
    return ret;
}

int t;
ll n, r, k;


int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld %lld", &n, &r, &k);
        vector<ll> s(max(r*r, k*k)+1), a(max(r, k));
        fill(a.begin(), a.end(), 0);
        for(int i = 0; i < r; i++) cin >> s[i];
        for(int i = 0; i < r; i++) cin >> a[i];

        for(int i = r; i <= max(r*r, k*k); i++) {
            s[i] = 0;
            for(int j = 0; j < r; j++)
                s[i] = (s[i] + a[j] * s[i-j-1]) % MOD;
        }
        r = max(r, k);
        
        /* cout << "S: "; */
        /* for(ll x : s) cout << x << " "; */
        /* cout << endl; */

        Matrix A(r+2);
        A.m[0][0] = A.m[0][1] = 1;
        for(int i = k+1; i < r+2; i++) A.m[i][i-k] = 1;

        for(int i = k; i > 0; i--) {
            int d = k-i;
            for(int j = 1; j < r+1-d; j++)
                A.m[i][j] = a[d+j-1] % MOD;

            for(int l = 0; l < d; l++)
                for(int j = 1; j < r+1; j++)
                    A.m[i][j] = (A.m[i][j] + a[l] * A.m[i+l+1][j]) % MOD;
        }

        ll h = (r+k)/k;

        vector<ll> b(r+2);
        b[0] = 0;
        for(int i = 1; i < r+2; i++) b[i] = s[h*k-i];
        for(int i = 1; i <= h-1; i++) 
            b[0] = (b[0] + s[k*i - 1]) % MOD;



        /* cout << "h:" << h << endl; */
        /* cout << "------" << endl; */
        /* for(ll x : b) printf("%lld\n", x); */
        /* cout << "-----" << endl; */

        /* cout << A; */

        if(n > h) printf("%lld\n", ((A^(n-h+1))*b)[0]);
        else {
            ll ans = 0;
            for(int i = 1; i <= n; i++)
                ans = (ans + s[k*i-1]) % MOD;
            printf("%lld\n", ans);
        }

    }   
}


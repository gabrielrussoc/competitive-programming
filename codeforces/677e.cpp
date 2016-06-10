#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 1004;
const ll modn = 1000000007;

int n;
char g[N][N];
int nz[8][N][N];
int q2[8][N][N];
int q3[8][N][N];
ll ans[8][N][N];
bool seen[8][N][N];
int r2, r3;
double gt;

int dx[] = {0, -1, 1, 0, -1, 1, -1, 1}; 
int dy[] = {1, 0, 0, -1, 1, 1, -1, -1};

double lg3 = log2(3);
double lg2 = 1;

/* 4 0 5
 * 1 x 2
 * 6 3 7 */

bool isval(int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= n) return false;
    return true;
}

ll mod (ll x) {
    return (x+modn)%modn;
}

void calc (int i, int j, int d) {
    if(seen[d][i][j]) return;
    seen[d][i][j] = true;
    int ni = i + dx[d];
    int nj = j + dy[d];
    if(!isval(ni,nj) || g[ni][nj] == '0') {
        nz[d][i][j] = 0;       
        return;
    }
    calc(ni, nj, d);
    q2[d][i][j] = q2[d][ni][nj] + (g[ni][nj] == '2');
    q3[d][i][j] = q3[d][ni][nj] + (g[ni][nj] == '3');
    nz[d][i][j] = 1 + nz[d][ni][nj];
}

void get (int i, int j) {
    for (int d = 0; d < 8; d++) calc (i, j, d);
    int r, t;
    r = t = inf;
    for(int k = 0; k < 4; k++) r = min(r, nz[k][i][j]), t = min(t, nz[k+4][i][j]);
    
    int a2, a3;
    gt = -inf;
    a2 = a3 = 0;
    for (int k = 0; k < 4; k++) {
        a2 += q2[k][i][j] - q2[k][r*dx[k]+i][r*dy[k]+j];
        a3 += q3[k][i][j] - q3[k][r*dx[k]+i][r*dy[k]+j];
    }
    double xab = a2*lg2 + a3*lg3;
    if (g[i][j] != '1') xab += g[i][j] == '2' ? lg2 : lg3;
    if (xab > gt) {
        gt = xab;
        r2 = a2 + (g[i][j] == '2');
        r3 = a3 + (g[i][j] == '3');
    } 
    
    a2 = a3 = 0;
    for (int k = 4; k < 8; k++) {
        a2 += q2[k][i][j] - q2[k][t*dx[k]+i][t*dy[k]+j];
        a3 += q3[k][i][j] - q3[k][t*dx[k]+i][t*dy[k]+j];
    }
    xab = a2*lg2 + a3*lg3;
    if (g[i][j] != '1') xab += g[i][j] == '2' ? lg2 : lg3;
    if (xab > gt) {
        gt = xab;
        r2 = a2 + (g[i][j] == '2');
        r3 = a3 + (g[i][j] == '3');
    } 
}

int main() {
    scanf("%d",&n);
    bool can = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf(" %c",&g[i][j]);
            if(g[i][j] != '0') can = true;
        }
    

    if(!can) {
        puts("0");
        return 0;
    }

    double best = -1;
    ll prn = 1;
    int b2, b3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(g[i][j] == '0') continue;
            get (i, j);
            if (gt > best) { best = gt; b2 = r2; b3 = r3; }
        }
    }
    for(int i = 0; i < b2; i++) prn = mod (prn * 2ll);
    for(int i = 0; i < b3; i++) prn = mod (prn * 3ll);
    cout << prn << endl;

}


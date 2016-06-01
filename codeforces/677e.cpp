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
const int modn = 1000000007;

int n;
char g[N][N];
int nz[8][N][N];
int q2[8][N][N];
int q3[8][N][N];
int ans[8][N][N];
bool seen[8][N][N];

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};

double lg3 = log2(3);
double lg2 = 1;

/* 0 1 2
 * 3 x 4
 * 5 6 7 */

bool isval(int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= n) return false;
    return true;
}

void calc (int i, int j, int d) {
    if(seen[d][i][j]) return;
    seen[d][i][j] = true;
    int ni = i + dx[d];
    int nj = j + dy[d];
    if(!isval(ni,nj) || g[ni][nj] == '0') {
        nz[d][i][j] = 0;       
        ans[d][i][j] = 1;
        return;
    }
    calc(ni, nj, d);
    q2[d][i][j] += q2[d][ni][nj];
    q3[d][i][j] += q3[d][ni][nj];
    
    

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


    



    

}


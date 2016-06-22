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
const int N = 1001;
const int modn = 1000000007;

int v[N][N];
int dj[] = {1,0,-1,0};
int di[] = {0,1,0,-1};

void boom (int i, int j, int k, int d) {
    v[i][j] = k;
    if(k == N*N) return;
    int nd = (d+1)%4;
    if(v[i+di[nd]][j+dj[nd]])
        boom(i+di[d],j+dj[d],k+1,d);
    else
        boom(i+di[nd],j+dj[nd],k+1,nd);
}

int main() {
    boom(N/2,N/2, 1, 0);
    int i, j;
    int sum = 0;
    for(i = 0, j = 0; i < N && j < N; i++, j++) sum += v[i][j];
    for(i = 0, j = N-1; i < N && j >= 0; i++, j--) sum += v[i][j];
    sum -= v[N/2][N/2];
    printf("%d\n",sum);
}


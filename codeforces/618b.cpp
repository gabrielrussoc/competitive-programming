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
const int N = 55;
const int modn = 1000000007;

int n;
int v[N][N], f[N];

int main() {
    scanf("%d",&n);   
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&v[i][j]);

    for(int k = 1; k <= n; k++){
        for(int i = 0; i < n; i++){
            int cont = 0;
            for(int j = 0; j < n; j++)
                if(v[i][j] == k) cont++;
            if(cont == n-k && !f[i]) {
                f[i] = k;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) printf("%d ",f[i]);
    putchar('\n');
}


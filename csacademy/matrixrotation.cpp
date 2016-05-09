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
//////////////01nn456789
const int N = 104;
const int modn = 1000000007;

int n;
int a[N][N];

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&a[i][j]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            int c = a[i][j] | a[n-j-1][i] | a[n-i-1][n-j-1] | a[j][n-i-1];
            printf("%d ",c);
        }
        putchar('\n');
    }
            
            
}


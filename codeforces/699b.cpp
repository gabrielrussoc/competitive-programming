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

int n, m;
char g[N][N];
int sl[N], sc[N]; 
int cnt;

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            scanf(" %c",&g[i][j]);
            cnt += g[i][j] == '*';
        }

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            sl[i] += g[i][j] == '*';
    
    for(int j = 0; j < m; j++) 
        for(int i = 0; i < n; i++)
            sc[j] += g[i][j] == '*';

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            if(sl[i] + sc[j] - (g[i][j] == '*') == cnt) {
                puts("YES");
                printf("%d %d\n",i+1,j+1);
                return 0;
            }

    puts("NO");

}


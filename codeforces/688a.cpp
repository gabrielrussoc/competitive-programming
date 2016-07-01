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

int v[N];
int n, d;

int main() {
    scanf("%d %d",&n,&d);
    for(int i = 0; i < d; i++) {
        char c;
        for(int j = 0; j < n; j++) {
            scanf(" %c",&c); 
            if(c == '1') v[i]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < d; i++) {
        int j;
        for(j = i; j < d; j++) if(v[j] == n) break;
        ans = max(ans,j-i);
    }
    printf("%d\n",ans);
}


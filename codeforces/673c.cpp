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
const int N = 5003;
const int modn = 1000000007;

int n;
int v[N];
int f[N];
int ans[N];

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",v+i), v[i]--;

    for(int i = 0; i < n; i++) {
        memset(f,0,sizeof f);       
        int maxf = 0, c;
        for(int j = i; j < n; j++) {
            int at = ++f[v[j]];
            if(at > maxf || (at == maxf && v[j] < c)) maxf = at, c = v[j];
            ans[c]++;
        }
    }
    
    for(int i = 0; i < n; i++) printf("%d ",ans[i]);
    putchar('\n');


}


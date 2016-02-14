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
const int N = 10000007;
const int modn = 1000000007;
    
int n,m;

int main() {
    scanf("%d %d",&n,&m);
    int k, ds, ts;
    k = n; ds = 1;
    while(k--) {
        if(ds % 3 == 0) ds++;
        ds++;
    }
    k = m; ts = 1;
    while(k--){
        if(ts % 2 == 0) ts++;
        ts++;
    }
    int maxi = max(3*(ts-1), 2*(ds-1));
    int j = 1;
    while(6*j < maxi){
        if(3*(ts-1) > 2*(ds-1)) {
            ts--;
            if(3*(ts-1) == 6*j) break; 
            if((ts-1) % 2 == 0) ts--;
        }
        else {
            ds--;
            if(2*(ds-1) == 6*j) break;
            if((ds-1) % 3 == 0) ds--;
        }
        j++;
        maxi = max(2*(ds-1),3*(ts-1));
    }
    maxi = max(2*(ds-1),3*(ts-1));
    printf("%d\n",maxi);
}


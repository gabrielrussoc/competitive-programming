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
const int N = 10004;
const int modn = 1000000007;

int main() {
    int a, b, n;
    scanf("%d %d %d",&n,&a,&b);
    int f = 1;
    if(b < 0) b = -b, f = -1;
    while(b--) {
        a += f;
        if(a == 0) a = n;
        if(a == n+1) a = 1;
    }
    printf("%d\n",a);
}


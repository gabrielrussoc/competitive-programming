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
    int n, t;
    int ans = 0;
    scanf("%d %d",&n, &t);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++){
            if(!j || j == i) ans += (t >= ((1<<(i+1))-1));
            else ans += (t >= ((1<<i)-1) + (1<<(i-1)));
        }
    }
    printf("%d\n",ans);
}


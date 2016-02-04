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

int a[33];
map<ll,int> m;

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    sort(a,a+n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll j = a[i];
        while(m[j]) j--;
        if(j == 0) continue;
        ans += j;
        m[j]++;
    }
    cout << ans << endl;
}


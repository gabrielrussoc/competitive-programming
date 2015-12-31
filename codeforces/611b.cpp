#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define ff first
#define ss second
using namespace std;
typedef long long ll;

//////////////0123456789
const int N = 100009;
const int A = 1000009;
const int modn = 1000000007;

int main (){
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for(int i = 1; i < 62; i++){
        ll x = (1ll<<i)-1;
        for(int j = 0; j < i-1; j++){
            ll p = x ^ (1ll << j);
            if(p >= a && p <= b) ans++;
        }
    }
    cout << ans << endl;
}

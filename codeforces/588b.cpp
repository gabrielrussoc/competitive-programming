#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
#define ff first
#define ss second
using namespace std;
typedef long long ll;


int main() {
    ll n, ans = 1, d = 2;
    cin >> n;
    while(n > 1) {
        if(n%d == 0){
            ans *= d;
            while(n%d == 0) n /= d;
        }
        if(d*d > n){
            ans *= n;
            break;
        }
        d++;
    }
    cout << ans << endl;
}

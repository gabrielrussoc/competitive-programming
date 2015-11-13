#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-8;
const int inf = INT_MAX;
const int modn = 1000000007;

//////////////0123456789
const int N = 100005;

int main(){
    int t;
    ll n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int x = log2(n);
        cout << (n*(n+1))/2 -  (2*((1ll<<(x+1))-1)) << endl;
    }
}


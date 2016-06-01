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
const int N = 100004;
const ll modn = 1000000007;

char s[N];
ll ans[100];

int get (char c) {
    if(c >= '0' && c <= '9') return c-'0';
    if(c >= 'A' && c <= 'Z') return c-'A'+10;
    if(c >= 'a' && c <= 'z') return c-'a'+36;
    if(c == '-') return 62;
    return 63;
}

int main() {
    for(int i = 0; i < 64; i++) {
        for(int k = 0; k < 64; k++)
            for(int j = 0; j < 64; j++)
                if((k&j) == i) ans[i]++;
    }
    scanf(" %s",s);
    ll res = 1;
    for(int i = 0; s[i]; i++){
        res *= ans[get(s[i])];
        res %= modn;
    }
    cout << res << endl;
}


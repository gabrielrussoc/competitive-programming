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

char s[N];
int f[33];

int main() {
    int n;
    scanf("%d",&n);
    if(n > 26) {
        puts("-1");
        return 0;
    }
    scanf(" %s", s);
    int ans = 0;
    for(int i = 0; s[i]; i++) {
        char c = s[i];
        f[c-'a']++;
        if(f[c-'a'] > 1) ans++;
    }
    printf("%d\n",ans);
}


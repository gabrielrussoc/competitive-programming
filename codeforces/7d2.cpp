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
const int N = 5000004;
const int modn = 1000000007;

typedef unsigned long long hash;

char s[N];
int n, memo[N];
hash x[N], he[N], hd[N], X = 33;

hash calce (int i, int j) {
    return he[j+1]-he[i]*x[j-i+1];
}

hash calcd (int i, int j) {
    return hd[j+1]-hd[i]*x[j-i+1];
}

int cv(char c) {
    return c-'a'+1;
}

int solve (int i) {
    if(i == 0) return 1;
    int &me = memo[i];
    if(me != -1) return me;
    if(calce(0,i) == calcd(n-i-1,n-1)) me = 1 + solve((i-1)/2);
    else me = 0;
    return me;
}

int main() {
    scanf(" %s",s);
    n = strlen(s);
    memset(memo,-1,sizeof memo);
    x[0] = 1;
    for(int i = 0; i < n; i++){
        he[i+1] = he[i]*X + cv(s[i]);
        hd[i+1] = hd[i]*X + cv(s[n-i-1]);
        x[i+1] = X*x[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += solve(i);
    printf("%d\n",ans);
}


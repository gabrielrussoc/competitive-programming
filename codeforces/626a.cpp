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

int n;
char s[205];

int ok(int i, int j){
    int x, y;
    x = y = 0;
    for(int k = i; k <= j; k++) {
        if(s[k] == 'U') y++;
        else if(s[k] == 'D') y--;
        else if (s[k] == 'R') x++;
        else x--;
    }
    return x == 0 && y == 0;
}

int main() {
    scanf("%d",&n);
    scanf(" %s",s);
    ll ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(ok(i,j)) ans++;
    printf("%d\n",ans);
}


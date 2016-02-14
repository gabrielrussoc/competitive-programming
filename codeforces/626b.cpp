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

int rr, rb, rg;

int vis[205][205][205];

void solve (int r, int g, int b){
    if (r + g + b == 1) {
        if(r) rr = 1;
        if (g) rg = 1;
        if (b) rb = 1;
    }
    if (vis[r][g][b]) return;
    vis[r][g][b] = 1;
    if(r > 1) solve (r-1,g,b);
    if(g > 1) solve (r,g-1,b);
    if(b > 1) solve (r,g,b-1);
    if(g && b) solve(r+1,g-1,b-1);
    if(r && b) solve(r-1,g+1,b-1);
    if(r && g) solve(r-1,g-1,b+1);
}

int main() {
    int n;
    scanf("%d",&n);
    int r,g,b;
    char c;
    r = g = b = 0;
    for(int i = 0; i < n; i++){
        scanf(" %c",&c);
        if(c == 'R') r++;
        else if(c == 'G') g++;
        else b++;
    }
    solve(r,g,b);
    if(rb) putchar('B');
    if(rg) putchar('G');
    if(rr) putchar('R');
    putchar('\n');
}


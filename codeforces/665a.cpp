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
    int a,b,ta,tb, h, m;
    scanf("%d %d",&a,&ta);
    scanf("%d %d",&b,&tb);
    scanf("%d:%d",&h,&m);
    int ini = h*60 + m;
    int fim = ini+ta;
    int ans = 0;
    for(int t = 60*5; t < 24*60; t += b)
        if(t < fim && t+tb > ini)
            ans++;
    printf("%d\n",ans);

}


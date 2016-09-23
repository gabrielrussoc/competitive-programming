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
int a[N], p[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    for(int i = 0; i < n; i++) p[i] = i;
    sort(p,p+n, cmp);
    for(int i = 0; i < (n/2); i++) printf("%d %d\n",p[i]+1,p[n-i-1]+1);
}


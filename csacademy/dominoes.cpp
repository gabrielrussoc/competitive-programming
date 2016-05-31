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
const int N = 1000004;
const int modn = 1000000007;

int v[N];
int n, k;
int up = 1e6;

int can (int mid) {
    int cont = 0;
    for(int i = 1; i <= mid; i++) cont += v[i];
    if(mid-cont <= k) return 1;
    for(int i = 2; i <= up-mid+1; i++) {
        cont -= v[i-1];
        cont += v[i+mid-1];
        if(mid-cont <= k) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        v[a] = 1;
    }
    int lo = 1, hi = 2e5;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if(can(mid)) lo = mid;
        else hi = mid-1;
    }
    printf("%d\n",lo);
}


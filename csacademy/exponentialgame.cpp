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
    int t;
    scanf("%d",&t);
    while(t--) {
        map<int, int> m;
        int a;
        int n;
        int ans = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) {
            scanf("%d",&a);
            m[a]++;
        }
        for(pii i : m) if(i.ss&1) ans = 1;
        if(ans) puts("A");
        else puts("B");
    }
}


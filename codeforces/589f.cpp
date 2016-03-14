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

int n, a[N], b[N], q[N], maxi;

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",a+i,b+i);
        maxi = max(maxi,b[i]);
    }

    int lo = 0, hi = maxi;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        for(int i = 0; i < n; i++) q[i] = 0;
        for(int i = 0; i < maxi; i++) {
            int k = -1, mini = inf;
            for(int j = 0; j < n; j++) 
                if(a[j] <= i && i < b[j])
                    if(b[j] < mini && q[j] < mid)
                        mini = b[j], k = j;
            if(k != -1) q[k]++;
        }
        bool ok = true;
        for(int i = 0; i < n && ok; i++) if(q[i] < mid) ok = false;
        if(ok) lo = mid;
        else hi = mid-1;
    }
    printf("%d\n",lo*n);
}


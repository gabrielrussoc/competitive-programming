#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int main() {
    int n;
    ll x[N], r[N];
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%lld %lld", x+i, r+i);

        for(int i = 0; i < n; i++) {
            ll mn = x[i] - r[i];
            ll mx = x[i] + r[i];
            int j = i;
            while(j >= 0 && x[j] >= mn) {
                mn = min(mn, x[j]-r[j]);
                j--;
            }
            int jj = i;
            while(jj < n && x[jj] <= mx) {
                mx = max(mx, x[jj] + r[jj]);
                jj++;
            }
            printf("%d%c", jj-j-1, " \n"[i==n-1]);
        }
    }
}


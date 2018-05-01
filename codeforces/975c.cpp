#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;
ll a[N], k[N], acc[N];
int n, q;

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) cin >> k[i];
    acc[0] = a[0];
    for(int i = 1; i < n; i++) acc[i] = acc[i-1] + a[i];

    ll before = 0;
    for(int i = 0; i < q; i++) {
        int j = upper_bound(acc, acc+n, k[i]+before) - acc;
        if(j == n) {
            j = 0;
            before = 0;
        } else before += k[i];
        cout << n - j << endl;
    }
}


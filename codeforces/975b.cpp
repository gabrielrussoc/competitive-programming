#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int n = 14;
ll a[n], b[n];

ll score(int s) {
    for(int i = 0; i < n; i++) b[i] = a[i];
    ll plus = b[s] / 14;
    ll left = b[s] % 14;
    b[s] = 0;
    for(int i = 0; i < n; i++) b[i] += plus;
    for(int i = 0; i < left; i++)
        b[(s+i+1)%n]++;
    ll ret = 0;
    for(int i = 0; i < n; i++)
        if(b[i]%2 == 0)
            ret += b[i];
    return ret;
}

int main() {
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++) if(a[i] > 0) ans = max(ans, score(i));
    cout << ans << endl;
}


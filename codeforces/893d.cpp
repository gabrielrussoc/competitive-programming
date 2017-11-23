#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int n;
ll d, a[N];

void imp() {
    puts("-1");
    exit(0);
}

int main() {
    scanf("%d %lld", &n, &d);
    for(int i = 0; i < n; i++) scanf("%lld", a+i);

    ll s = 0;
    ll h = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
        if(s > d) imp();
        if(a[i] == 0 && s < 0) {
            if(h >= -s) h += s;
            else {
                h = d;
                ans++;
            }
            s = 0;
        }
        h = min(h, d-s);
    }
    printf("%d\n", ans);


}


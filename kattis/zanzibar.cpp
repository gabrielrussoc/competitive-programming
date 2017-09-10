#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int t;
ll last, at;

int main() {
    scanf("%d", &t);
    while(t--) {
        last = -1;
        ll ans = 0;
        while(scanf("%lld", &at) && at != 0) {
            if(last != -1) {
                if(at > 2ll*last)
                    ans += at - 2*last;
            }
            last = at;
        } 
        printf("%lld\n", ans);
        
    }
}


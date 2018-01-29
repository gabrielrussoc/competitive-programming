#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

char s[5005];

int main() {
    scanf(" %s", s);
    int n = strlen(s);
    int ans = 0;
    int old = 0;
    for(int l = 0; l < n; l++) {
        int o = 0, q = 0, a = 0;
        for(int r = l; r < n; r++) {
            if(s[r] == '?') {
                q++;
                if(o-a > 0) a++;
            }
            else if(s[r] == '(') {
                o++;
            }
            else {
                o--;
                if(a > 0 && o-a < 0) a--;
            }

            if(o-a < 0) {
                if(q > a) q--;
                else break;
                o++;
                if((q-a)%2 == 0) ans++;
            } else if(o-a == 0) {
                if((q-a)%2 == 0) ans++;
            } 

            /* if(ans > old) printf("%d %d\n", l, r); */
            old = ans;
        }
    }
    printf("%d\n", ans);
}


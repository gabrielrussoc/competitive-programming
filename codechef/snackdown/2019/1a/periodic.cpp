#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf(" %d", &t);

    while (t--){
        int n;
        scanf(" %d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf(" %d", &a[i]);
            if(a[i] != -1) a[i]--;
        }

        int ans = -1;
        for(int k = 1; k <= 2*n+1; k++) {
            int cand = -1;
            bool can = true;
            for(int i = 0; i < n && can; i++) {
                if(a[i] == -1) continue;
                if(a[i] >= k) can = false;
                int cur = (((a[i] - i) % k) + k) % k;
                /* if(k == 4) printf("%d: %d\n", i, cur); */
                if(cur < 0) can = false;
                if(cand == -1) cand = cur;
                else if(cand != cur) can = false;
            }
            if(can) ans = k;
        }
        if(ans == n+1) puts("inf");
        else if(ans == -1) puts("impossible");
        else printf("%d\n", ans);
    }
}

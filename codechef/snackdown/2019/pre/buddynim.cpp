#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 250;

int t, n, m;
int a[N], b[N];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", a+i);
        for(int i = 0; i < m; i++) scanf("%d", b+i);
        sort(a, a+n, greater<int>());
        sort(b, b+m, greater<int>());
        while(n > 0 && a[n-1] == 0) n--;
        while(m > 0 && b[m-1] == 0) m--;
        bool ans = true;
        if(n == m) {
            ans = false;
            for(int i = 0; i < n; i++) {
                if(a[i] != b[i])
                    ans = true;
            }
        }
        if(ans) puts("Alice");
        else puts("Bob");
    }

}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1123;
int t, n, v[12];
char s[N];
char g[] = "ROYGBV";

bool valid(int i, int j) {
    return s[i] != g[(j+1)%6] && s[i] != g[(j+5)%6] && g[j] != s[i];
}

char nextc(int l) {
    int idx = max_element(v, v+6) - v;
    if(l == -1) {
        v[idx]--;
        return g[idx];
    }
    if(l == n-2) l = 0;
    idx = -1;
    int maxi = 0;
    for(int i = 0; i < 6; i++) {
        if(valid(l, i) && v[i] > maxi) {
            idx = i;
            maxi = v[i];
        }
    }
    if(idx == -1) return '$';
    v[idx]--;
    return g[idx];
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d",&n);
        for(int i = 0; i < 6; i++) scanf("%d", v+i); // R O Y G B V
        bool xab = false;
        for(int i = 0; i < n; i++) {
            s[i] = nextc(i-1);
            if(s[i] == '$') xab = true;
        }
        s[n] = 0;
        xab = false;
        printf("Case #%d: ", tc);
        if(xab) puts("IMPOSSIBLE"); 
        else puts(s);
    }
}


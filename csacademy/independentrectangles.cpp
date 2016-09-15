#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 112345;

int h[N], w[N], mw[12*N], p[N], wait[N], ps;
int n;
set<int> s;
bool comp(int i, int j) {
    return w[i] > w[j];
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",w+i, h+i);
        p[i] = i;
    }
    sort(p,p+n, comp);
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        int hh = h[p[i]];
        if(s.upper_bound(hh) == s.end()) ans++;
        if(!ps || wait[ps-1] > w[p[i]]) {
            s.insert(hh);
            while(ps) s.insert(wait[--ps]);
        } else wait[ps++] = hh;
    }
    printf("%d\n",ans);
}


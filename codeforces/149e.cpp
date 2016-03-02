#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100004;
const int modn = 1000000007;

char s[2*N], t[1005], r[2*N];
int n, p, ze[2*N], zd[2*N], pref[1005], suf[1005];

void zfunc(char *s, int *z) {
    int l, r;
    l = r = 0;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && s[r] == s[r-l]) r++;
            z[i] = r-l; r--;
        } else {
            int k = i-l;
            if(z[k] < r-i+1) z[i] = z[k];
            else {
                l = i;
                while(r < n && s[r] == s[r-l]) r++;
                z[i] = r-l; r--;
            }
        }
    }
}

int main() {
    int maxm = 1000, m;
    for(int i = 0; i < maxm; i++) s[i] = r[i] = '#';
    scanf(" %s", s+maxm);
    n = strlen(s);
    strcpy(r, s);
    reverse(r+maxm,r+n);
    scanf(" %d",&m);
    int ans = 0;
    while(m--){
        int i;
        scanf(" %s", t); p = strlen(t);
        if(p == 1) continue;

        for(i = 0; i < p; i++) s[i] = r[i] = t[i];
        for(i = p; i < maxm; i++) s[i] = r[i] = '#';
        reverse(r,r+p);

        zfunc(s, ze);
        zfunc(r, zd);
        
        for(i = 0; i <= p; i++) pref[i] = n, suf[i] = -1;

        for(i = maxm; i < n; i++) {
            pref[ze[i]] = min(pref[ze[i]], i-maxm);
            suf[zd[i]] = max(suf[zd[i]], n-i-1);
            if(ze[i] == p) break;
        }
        if(i < n) { ans++; continue; }
    
        for(i = p-1; i >= 0; i--) {
            pref[i] = min(pref[i], pref[i+1]);
            suf[i] = max(suf[i], suf[i+1]);
        }
    
        //for(i = 1; i < p; i++) printf("%d :: %d %d\n",i,pref[i], suf[i]);
        for(i = 1; i < p; i++) if(pref[i] < suf[p-i] - p + 2) { ans++; break;}
            
    }
    printf("%d\n",ans);
}


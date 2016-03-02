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
int n, m, ze[2*N], zd[2*N], pref[1005], suf[1005];

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
    int maxm = 1000;
    for(int i = 0; i < maxm; i++) s[i] = '#';
    scanf(" %s", s+maxm);
    n = strlen(s);
    strcpy(r, s);
    reverse(r+maxm,r+n);
    scanf(" %d",&m);
    int ans = 0;
    for(int i = 0; i < m; i++) {
        scanf(" %s", t);
        int j;
        for(j = 0; t[j]; j++) s[j] = r[j] = t[j];
        for(int k = j; k < maxm; k++) s[k] = r[k] = '#';
        reverse(r,r+j);
        zfunc(s, ze);
        zfunc(r, zd);
        if(j == 1) continue;
        if(ze[maxm] == j) {
            ans++;
            continue;
        }
        for(int k = 0; k <= j; k++) pref[k] = n, suf[k] = -1;
        for(int k = maxm; k < n; k++) pref[ze[k]] = min(pref[ze[k]], k-maxm), suf[zd[k]] = max(suf[zd[k]], n-k-1);
        for(int k = 0; k <= j; k++)
            if(k<j) suf[k] = max(suf[k], suf[k+1]), pref[k] = min(pref[k],pref[k+1]);
        for(int k = 1; k < j; k++) if(pref[k] < suf[j-k] - j + 2) { ans++; break;}
            
    }
    printf("%d\n",ans);
}


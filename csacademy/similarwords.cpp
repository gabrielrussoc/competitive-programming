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

int n;
char s[N], t[N];

int main() {
    int ans = 0;
    scanf("%d",&n);
    scanf(" %s",s);
    int p = strlen(s);
    for(int i = 0; i < n; i++) {
        scanf(" %s", t);
        int q = strlen(t);
        int cont = 0;
        if(p == q) {
            for(int j = 0; j < p; j++) if(s[j] != t[j]) cont++;
            if(cont <= 1) ans++;
        } else if (p+1 == q) {
            int k = 0;
            for(int j = 0; j < p; j++) {
                if(t[k++] != s[j]) {
                    j--;
                    cont++;
                    if(cont > 1) break;
                }
            }
            if(cont <= 1) ans++;
        } else if (p == q+1) {
            int k = 0;
            for(int j = 0; j < q; j++) {
                if(s[k++] != t[j]) {
                    j--;
                    cont++;
                    if(cont > 1) break;
                }
            } 
            if(cont <= 1) ans++;
        }
    }
    printf("%d\n",ans);
}


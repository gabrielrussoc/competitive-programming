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
const int N = 10004;
const int modn = 1000000007;

char s[305], st[305];
int ps;

bool match (char a, char b) {
    if(a > b) swap(a,b);
    if(a == 'B' && b == 'S') return true;
    if(a == 'C' && b == 'F') return true;
    return false;
}

int main() {
    while(scanf(" %s",s) != EOF) {
        ps = 0;
        int ans = 0;
        for(int i = 0; s[i]; i++) {
            if(ps && match(s[i],st[ps-1])) {
                ans++;
                ps--;
            } else st[ps++] = s[i];
        }
        printf("%d\n",ans);
    }
}


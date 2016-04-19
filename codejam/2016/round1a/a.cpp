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

int t, n, cont;
char s[N];

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        cont = 0;
        scanf(" %s", s);
        n = strlen(s);
        char f = 0;
        string ans;
        for(int i = 0; i < n; i++) {
            if (s[i] >= f) {
                ans = s[i] + ans;
                f = ans[0];
            } else {
                ans += s[i];
            }
        }
        printf("Case #%d: %s\n",tc,ans.c_str());
    }
}


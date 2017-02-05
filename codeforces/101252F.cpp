#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;

struct best {
    int c;
    int dp;
    int i;
    best () {}
    best(int c, int dp, int i) : c(c), dp(dp), i(i) {}
    bool operator<(const best &o) const {
        if(dp != o.dp) return dp > o.dp;
        return c < o.c;
    }
};
map<int, set<best>::iterator> m;
int dp[N], c[N], nx[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", c+i);
    set<best> s;
    s.insert(best(-7, 0, -1));
    for(int i = n-1; i >= 0; i--) {
        best f = best(-7, 0, -1);
        for(best b : s) if(abs(b.c - c[i]) != 1) { f = b; break; }
        int p = f.dp;
        dp[i] = 1 + p; 
        nx[i] = f.i;
        if(m.count(c[i])) {
            if(m[c[i]]->dp < dp[i]) {
                s.erase(m[c[i]]);
                m[c[i]] = s.insert(best(c[i], dp[i], i)).first;
            }
        } else {
            m[c[i]] = s.insert(best(c[i], dp[i], i)).first;
        }
    }
    int j = max_element(dp, dp+n) - dp;
    printf("%d\n", n - dp[j]);
    int p = j;
    while(j != -1) {
        printf("%d ", c[j]);
        j = nx[j];
    }
    putchar('\n');
}


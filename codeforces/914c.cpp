#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1005;
const ll MOD = 1e9+7;
char s[N];
int k, l;
set<int> g;

ll memo[N][N][2];
int vis[N][N][2], turn;

int step(int n) {
    if(n == 1) return 1;
    return 1 + step(__builtin_popcount(n));
}

ll dp(int i, int q, bool pre) {
    if(q > l) return 0;
    if(i == l) return g.count(q);
    ll &me =  memo[i][q][pre];
    if(vis[i][q][pre] == turn) return me;
    vis[i][q][pre] = turn;

    me = dp(i+1, q, pre && (s[i] == '0')) % MOD;
    if(!pre || s[i] == '1') me = (me + dp(i+1, q+1, pre && s[i] == '1')) % MOD;
    return me % MOD;
}

int main() {
    turn++;
    scanf(" %s", s);
    scanf("%d", &k);
    if(k == 0) {
        puts("1");
        return 0;
    }
    l = strlen(s);
    for(int goal = 1; goal <= l; goal++) {
        if(step(goal) == k)
            g.insert(goal);
    }
    ll ans = dp(0, 0, true);
    if(k == 1) ans = (ans + MOD - 1) % MOD;
    printf("%lld\n", ans);

}


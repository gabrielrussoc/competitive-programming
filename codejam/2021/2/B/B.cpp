#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
const int inf = 0x3f3f3f3f;

map<pair<int, int>, int> memo;
map<pair<int, int>, bool> vis;

int dp(int c, int n) {
    if(n == 0) return 0;
    if(n%c) return -inf;
    pair<int, int> key = {c, n};
    if(vis[key]) return memo[key];
    vis[key] = true;
    int ans = -inf;
    for(int k = 2; k*c <= n; k++) {
        int nxt = k*c;
        if(nxt < 3) continue;
        ans = max(ans, 1 + dp(nxt, n-nxt));
    }
    return memo[key] = ans;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        printf("Case #%d: %d\n", tc, dp(1, n));
    }

}


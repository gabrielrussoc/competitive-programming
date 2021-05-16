#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 17;
int d[MAX];

int bin(const string& s) {
    int b = 1;
    int n = s.size();
    int ret = 0;
    for(int i = n-1; i>=0; i--) {
        ret += b * (s[i] - '0');
        b *= 2;
    }
    return ret;
}

int correct_not(int x) {
    if(x == 0) return 1;
    int clz = __builtin_clz(x);
    return (~((-1)<<(32-clz)))&(~x);
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        string S, E;
        cin >> S >> E;
        int s = bin(S);
        int e = bin(E);

        for(int i = 0; i < MAX; i++) d[i] = 2*MAX;

        queue<int> q;
        d[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == e) break;

            int db = 2*u;
            int nt = correct_not(u);

            if(db < MAX && d[db] > d[u] + 1) {
                q.push(db);
                d[db] = d[u] + 1;
            }

            if (nt < MAX && d[nt] > d[u] + 1) {
                q.push(nt);
                d[nt] = d[u] + 1;
            }
        }

        if(d[e] != 2*MAX) printf("Case #%d: %d\n", tc, d[e]);
        else printf("Case #%d: IMPOSSIBLE\n", tc);
    }
}



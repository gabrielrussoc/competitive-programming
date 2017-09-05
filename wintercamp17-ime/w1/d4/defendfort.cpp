#include <bits/stdc++.h>
#define debug(args...) //fprintf(stderr, args)
#define ff first
#define ss second
using namespace std;

typedef long long lint;
typedef pair<lint, lint> pii;

int main() {
    lint n, d;
    cin >> n >> d;
    priority_queue<pii> pq;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        pii aux;
        cin >> aux.ss >> aux.ff;
        pq.push(aux);
        ans += aux.ss;
    }
    while (!pq.empty() && d) {
        pii p = pq.top();
        debug("k = %d\na = %d\n", p.ff, p.ss);
        pq.pop();
        lint dd = min(p.ss / p.ff, d);
        ans -= dd * p.ff;
        lint rem = p.ss - (p.ss / p.ff) * p.ff;
        if (rem != 0) pq.push(pii(rem, rem));
        d -= dd;
        debug("usado %d\nrestante %d\n", dd, d);
    }
    cout << ans << endl;
    return 0;
}

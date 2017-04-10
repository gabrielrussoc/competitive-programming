#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct lt {
    bool operator() (const pii &a, const pii &b) const {
        int l1 = a.first, r1 = a.second;
        int l2 = b.first, r2 = b.second;
        int m1 = l1 + (r1-l1)/2, m2 = l2 + (r2-l2)/2;
        l1 = m1 - l1 - 1;
        r1 = r1 - m1 - 1;
        l2 = m2 - l2 - 1;
        r2 = r2 - m2 - 1;
        if(l1 != l2) return l1 > l2;
        if(r1 != r2) return r1 > r2;
        return m1 < m2;
    }
};

set<pii, lt> s;

int main() {
    int t, n, k;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        s.clear();
        scanf("%d %d",&n, &k);
        s.insert(pii(0, n+1));
        pii at;
        int m;
        while(k--) {
            auto it = s.begin();
            at = *it;
            s.erase(it);
            m = at.first + (at.second - at.first) / 2;
            pii a = pii(at.first, m);
            pii b = pii(m, at.second);
            if(a.second - a.first > 1) s.insert(a);
            if(b.second - b.first > 1) s.insert(b);
        }
        printf("Case #%d: %d %d\n", tc, at.second - m - 1, m - at.first - 1);
    }
}


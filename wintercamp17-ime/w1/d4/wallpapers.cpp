#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

struct wall {
    int w1, w2, h1, h2;
    bool operator<(const wall &o) const {
        if(w2-w1 != o.w2-o.w1) return w2-w1 > o.w2-o.w1;
        return h2-h1 > o.h2-o.h1;
    }
    wall () {}
    wall(int w1, int w2, int h1, int h2) : w1(w1), w2(w2), h1(h1), h2(h2) {}
} v[N];

bool cover(wall &a, wall &b) {
    return a.w1 <= b.w1 &&
        a.w2 >= b.w2 &&
        a.h1 <= b.h1 &&
        a.h2 >= b.h2;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            int w1, w2, h1, h2;
            cin >> w1 >> w2 >> h1 >> h2;
            v[i] = wall(w1, w2, h1, h2);
        }
        sort(v, v+n);
        bool ans = true;
        for(int i = 1; i < n && ans; i++) {
            if(!cover(v[0], v[i])) ans = false;
        }
        if(ans) puts("ANO");
        else puts("NIE");
    }
}


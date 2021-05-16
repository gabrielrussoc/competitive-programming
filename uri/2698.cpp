#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct Interval {
    int l, r, c;
    Interval(){}
    Interval(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}
    bool operator<(const operator &o) const {
        return l < o.l;
    }
};

int l, c, n;

int main() {
    scanf("%d %d %d", &l, &c, &n);
    set<Interval> s;
    s.insert({1, l, 1});
    for(int i = 0; i < n; i++) {
        int p, x, a, b;
        scanf("%d %d %d %d", &p, &x, &a, &b);
        auto it = --s.upper_bound({a, b});
        Interval cur = *it;
        s.erase(it);
        s.insert({cur.l, a-1, cur.c});
        s.insert({});
    }
}


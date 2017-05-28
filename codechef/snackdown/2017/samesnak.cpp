#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct point {
    int x, y;
    point () {}
    point (int x, int y) : x(x), y(y) {}
    point operator- (const point &o) const {
        return point(x - o.x, y - o.y);
    }
    bool operator== (const point &o) const {
        return x == o.x && y == o.y;
    }
};

struct segment {
    point a, b;
    segment () {}
    segment (point a, point b) : a(a), b(b) {}
    int dir() {
        point m = b - a;
        return !!m.x;
    }
    bool unit() {
        return a == b;
    }
};

segment read(){
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    point a = point(x1, y1);
    point b = point(x2, y2);
    return segment(a, b);
}

bool share_corner(segment f, segment s) {
    return f.a == s.a || f.a == s.b || f.b == s.a || f.b == s.b;
}

bool intersect(int a, int b, int c, int d) {
    if(a > b) swap(a,b);
    if(c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}

bool parallel_intersect(segment f, segment s) {
    if(!f.unit() && !s.unit() && f.dir() != s.dir()) return false;
    point a = f.a;
    point b = f.b;
    point c = s.a;
    point d = s.b;
    return intersect(a.x, b.x, c.x, d.x) && intersect(a.y, b.y, c.y, d.y);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        segment f = read();
        segment s = read();
        if(share_corner(f, s) || parallel_intersect(f, s)) puts("yes");
        else puts("no");
    }
}


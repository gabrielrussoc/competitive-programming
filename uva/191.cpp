#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int xs,ys,xe,ye,xl,xr,yt,yb, n;

struct point {
    int x, y;
    point () {}
    point (int x, int y):x(x), y(y) {}
    point operator+ (const point &o) {
        return point(x+o.x, y+o.y);
    }
    point operator- (const point &o) {
        return point(x-o.x, y-o.y);
    }
    int operator* (const point &o) {
        return x*o.x + y*o.y;
    }
    int operator^ (const point &o) {
        return x*o.y - o.x*y;
    }
};

int sgn (int x) {
    return (x > 0) - (x < 0);
}

int area(point a, point b, point c) {
    return (b-a)^(c-a);
}

bool intersect_l (int a, int b, int c, int d) {
    if (a > b) swap(a,b);
    if (c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}

bool intersect (point a, point b) {
    point c = point(xs,ys);
    point d = point(xe,ye);
    return intersect_l (a.x,b.x,c.x,d.x)
        && intersect_l (a.y,b.y,c.y,d.y)
        && sgn(area(c,a,b)) * sgn(area(d,a,b)) <= 0
        && sgn(area(a,c,d)) * sgn(area(b,c,d)) <= 0;
}

bool inb(int x, int l, int r) {
    return x >= l && x <= r;
}

bool retardo () {
    return inb(xs,xl,xr) && inb(ys,yb,yt) && inb(xe,xl,xr) && inb(ye,yb,yt); 
}

int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d %d %d %d %d %d %d %d",&xs,&ys,&xe,&ye,&xl,&yt,&xr,&yb);
        if(xl > xr) swap(xl,xr);
        if(yb > yt) swap(yb,yt);
        if (intersect(point(xl, yb), point(xr, yb))) puts("T");
        else if (intersect(point(xr, yb), point(xr, yt))) puts("T");
        else if (intersect(point(xl, yt), point(xr, yt))) puts("T");
        else if (intersect(point(xl, yt), point(xl, yb))) puts("T");
        else if (retardo()) puts("T"); 
        else puts("F");
    }
}


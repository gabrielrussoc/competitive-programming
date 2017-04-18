#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 11234;
int x[N], y[N], p[N], h[N], ps;

bool lex(int i, int j) {
    if(x[i] == x[j]) return y[i] < y[j];
    return x[i] < x[j];
}

int cross(int i, int j, int k) {
    return (x[i]-x[k]) * (y[j]-y[k]) - (x[j]-x[k]) * (y[i]-y[k]);
}

int norm2(int i) {
    return x[i] * x[i] + y[i] * y[i];
}

int sgn(int x) {
    return (x > 0) - (x < 0);
}

bool ang(int i, int j) {
    int o = sgn(cross(i, j, p[0]));
    if(o == 0) return norm2(i) < norm2(j);
    return o > 0;
}

int area(int i, int j, int k) {
    return abs(cross(i, j, k));
}

int tsi(int i, int j) {
    int lo = i, hi = j;
    while(lo < hi - 2) {
        int t = (hi - lo) / 3;
        int m1 = lo + t;
        int m2 = lo + 2 * t;
        if(area(h[i], h[j], h[m1]) < area(h[i], h[j], h[m2])) lo = m1;
        else hi = m2;
    }
    int ans = 0;
    for(int q = lo; q <= hi; q++) ans = max(ans, area(h[i], h[j], h[q]));
    return ans;
}

int tso(int i, int j) {
    int lo = j, hi = ps + i;
    while(lo < hi - 2) {
        int t = (hi - lo) / 3;
        int m1 = lo + t;
        int m2 = lo + 2 * t;
        if(area(h[i], h[j], h[m1%ps]) < area(h[i], h[j], h[m2%ps])) lo = m1;
        else hi = m2;
    }
    int ans = 0;
    for(int q = lo; q <= hi; q++) ans = max(ans, area(h[i], h[j], h[q%ps]));
    return ans;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", x+i, y+i);
            p[i] = i;
        }
        sort(p, p+n, lex);
        sort(p+1, p+n, ang);
        ps = 0;
        h[ps++] = p[0]; 
        h[ps++] = p[1];
        for(int i = 2; i < n; i++) {
            while(ps > 1 && sgn(cross(p[i], h[ps-1], h[ps-2])) >= 0) ps--;
            h[ps++] = p[i];
        }
        int ans;
        if(ps == 2) {
            ans = 0;
        } else if(ps == 3) {
            ans = area(h[0], h[1], h[2]);
        } else {
            ans = 0;
            for(int i = 0; i < ps; i++)
                for(int j = i + 2; j < ps; j++) {
                    ans = max(ans, tsi(i, j) + tso(i, j));               
                    //printf("Ans para %d %d x %d %d = %d + %d\n", x[h[i]], y[h[i]], x[h[j]], y[h[j]], tsi(i, j), tso(i, j));
                }
        }
        printf("%d", ans / 2);
        if(ans%2) printf(".5");
        putchar('\n');
    }
}


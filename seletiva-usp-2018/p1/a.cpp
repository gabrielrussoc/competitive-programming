#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 30005;
int n, t, a[N];

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int pos(int x) {
    int l = 0, r = n;
    while(l < r) {
        int m = (l+r)/2;
        if(a[m] * x > t) r = m;
        else l = m+1;
    }
    return n - l;
}

int neg(int x) {
    int l = -1, r = n-1;
    while(l < r) {
        int m = (l+r+1)/2;
        if(a[m] * x > t) l = m;
        else r = m-1;
    }
    return l+1;
}

int main() {
    int tc = 1;
    while(scanf("%d %d", &n, &t) && n) {
        for(int i = 0; i < n; i++) scanf("%d", a+i);
        sort(a, a+n);
        int num = 0, den = n*n;
        for(int i = 0; i < n; i++) {
            if(a[i] >= 0) num += pos(a[i]); 
            else num += neg(a[i]);
        }
        int d = gcd(num,den);
        printf("Case %d: %d/%d\n", tc++, num/d, den/d);

    }
}


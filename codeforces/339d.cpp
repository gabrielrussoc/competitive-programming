#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = (1<<19);
int n, m;
int a[N], tree[N];

int op(int a, int b, int d) {
    if((n&1 && !d) || (!(n&1) && d)) return a|b;
    return a^b;
}

void build(int k = 1, int l = 0, int r = (1<<n)-1, int d = 0) {
    if(l == r) {
       tree[k] = a[l];
       return;
    } 
    int m = (l+r)/2;
    build(2*k, l, m, !d);
    build(2*k+1, m+1, r, !d);
    tree[k] = op(tree[2*k], tree[2*k+1], d);
}

void update(int i, int v, int k = 1, int l = 0, int r = (1<<n)-1, int d = 0) {
    if(l == r) {
        tree[k] = v;
        return;
    }
    int m = (l+r)/2;
    if(i <= m) update(i, v, 2*k, l, m, !d);
    else update(i, v, 2*k+1, m+1, r, !d);
    tree[k] = op(tree[2*k], tree[2*k+1], d);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < (1<<n); i++) scanf("%d", a+i);
    build();
    while(m--) {
        int p, b;
        scanf("%d %d", &p, &b);
        p--;
        update(p, b);
        printf("%d\n", tree[1]);
    }
}


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds
#define pb push_back
using namespace std;
typedef long long ll;
namespace GNU { typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; }
using GNU::ordered_set;

const int N = 112345;

struct eng {
    int a, b, c;
    eng () {}
    eng(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator<(const eng &o) {
        if(a != o.a) return a < o.a;
        if(b != o.b) return b < o.b;
        return c < o.c;
    }
} v[N];

ordered_set bit[N];

int n;

void upd(int idx, int val) {
    for(int i = idx+2; i < n+9; i += i&-i)
        bit[i].insert(val);
}

int qry(int idx, int y) {
    int ans = 0;
    for(int i = idx+2; i > 0; i -= i&-i) {
        ans += bit[i].order_of_key(y);
    }
    return ans;
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v[i] = eng(a, b, c);
        }
        for(int i = 0; i < n+9; i++) bit[i].clear();

        sort(v, v+n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x = v[i].b, y = v[i].c;
            if(!qry(x, y)) ans++;
            upd(x, y);
        }
        printf("%d\n", ans);
    }
}


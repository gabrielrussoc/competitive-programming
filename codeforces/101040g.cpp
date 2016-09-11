#include <bits/stdc++.h>
#define pb push_back
#define rotate blabla
using namespace std;
typedef long long ll;

const int N = 1e6+7;

int x, ts, lc[N], rc[N], h[N], key[N], t, n;
int ans[5];

void resize(int t) {
    if(!t) return;
    h[t] = 1 + max(h[lc[t]], h[rc[t]]);
}

int right_rotation(int t) {
    int aux = t;
    t = lc[t];
    lc[aux] = rc[t];
    rc[t] = aux;
    resize(rc[t]); resize(t);
    return t;
}

int left_rotation(int t) {
    int aux = t;
    t = rc[t];
    rc[aux] = lc[t];
    lc[t] = aux;
    resize(lc[t]); resize(t);
    return t;
}

int balance (int t, int x) {
    int fb = h[lc[t]] - h[rc[t]];
    if (fb > 1 && x < key[lc[t]]) {
        t = right_rotation(t);
        ans[0]++;
    } else if (fb > 1 && x >= key[lc[t]]) {
        lc[t] = left_rotation(lc[t]);
        t = right_rotation(t);
        ans[2]++;
    } else if (fb < -1 && x >= key[rc[t]]) {
        t = left_rotation(t);
        ans[1]++;
    } else if (fb < -1 && x < key[rc[t]]){
        rc[t] = right_rotation(rc[t]);
        t = left_rotation(t);
        ans[3]++;
    }
    return t;
}

int insert (int t, int x) {
    if(!t) {
        key[ts] = x;
        h[ts] = 1;
        return ts++;
    }
    if (key[t] <= x) rc[t] = insert(rc[t], x);
    else lc[t] = insert(lc[t], x);
    resize (t);
    t = balance(t, x);
    return t;   
}

void show(int t) {
    if(!t) return;
    printf("(%d)", key[t]);
    show(lc[t]);
    show(rc[t]);
}

int main() {
    ts = 1;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&x);
        t = insert (t, x);
    }
    show(t);
    putchar('\n');
    for(int i = 0; i < 4; i++) printf("%d ",ans[i]);
    putchar('\n');
}



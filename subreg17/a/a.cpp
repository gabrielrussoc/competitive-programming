#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int calc(int freq[]) {
    int maxi = *max_element(freq, freq+9);
    for(int i = 8; i >= 0; i--) {
        if(freq[i] == maxi) return i;
    }
    return 0;
}

int buf[9];

struct node {
    int freq[9];
    int mode;
    node() {
        for(int i = 0; i < 9; i++) freq[i] = 0;
    }
    node(int _freq[], int _mode) {
        for(int i = 0; i < 9; i++) freq[i] = _freq[i];
        mode = _mode;
    }
    node operator+ (const node &o) const {
        for(int i = 0; i < 9; i++)
            buf[i] = freq[i] + o.freq[i];
        return node(buf, calc(buf));
    }
    void shift(int q) {
        q %= 9;
        for(int i = 0; i < 9; i++) {
            buf[i] = freq[(i+9-q)%9];
        }
        for(int i = 0; i < 9; i++) freq[i] = buf[i];
        mode = (mode + q) % 9;
    }
};

node tree[4*N];
int lazy[4*N];
int n, q;

void unlazy(int k, bool leaf) {
    tree[k].shift(lazy[k]);
    if(!leaf) {
        lazy[2*k] += lazy[k];
        lazy[2*k+1] += lazy[k];
    }
    lazy[k] = 0;
}

void update(int fl, int fr, int val, int k = 1, int l = 0, int r = n-1) {
    unlazy(k, l==r);
    if(l >= fl && r <= fr) {
        lazy[k] += val;
        unlazy(k, l==r);
        return;
    }
    if(r < fl || l > fr) return;
    int m = (l+r)/2;
    update(fl, fr, val, 2*k, l, m);
    update(fl, fr, val, 2*k+1, m+1, r);
    tree[k] = tree[2*k] + tree[2*k+1];
}

node query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    unlazy(k, l==r);
    if(l >= fl && r <= fr) return tree[k];
    if(r < fl || l > fr) return node();
    int m = (l+r)/2;
    return query(fl, fr, 2*k, l, m) + query(fl, fr, 2*k+1, m+1, r);
}

void init(int k = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[k].freq[1] = 1;
        tree[k].mode = 1;
        return;
    }
    int m = (l+r)/2;
    init(2*k, l, m);
    init(2*k+1, m+1, r);
    tree[k] = tree[2*k] + tree[2*k+1];
}

void answer(int k = 1, int l = 0, int r = n-1) {
    unlazy(k, l==r);
    if(l == r) {
        cout << tree[k].mode << endl;
        return;
    }
    int m = (l+r)/2;
    answer(2*k, l, m);
    answer(2*k+1, m+1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    init();
    while(q--) {
        int a, b;
        cin >> a >> b;
        node ans = query(a,b);
        update(a, b, ans.mode);
    }
    answer();
}


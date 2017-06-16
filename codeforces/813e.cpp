#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100004;
int n, q, k;
queue<int> f[N];

struct node {
    int val;
    node *left, *right;
    node (int val = 0) : val(val), left(NULL), right(NULL) {}
};

node *version[N];

void build(node *root, int l = 0, int r = n - 1) {
    if(l == r) {
        root->val = 0;
        return;
    }
    int m = (l + r) / 2;
    root->left = new node();
    root->right = new node();
    build(root->left, l, m);
    build(root->right, m+1, r);
    root->val = root->left->val + root->right->val;
}

void update(node *prev, node *cur, int i, int val, int l = 0, int r = n - 1) {
    if(l == r) {
        cur->val = val;
        return;
    }
    int m = (l + r) / 2;
    if(i <= m) {
        cur->left = new node();
        update(prev->left, cur->left, i, val, l, m);
        cur->right = prev->right;
    } else {
        cur->right = new node();
        update(prev->right, cur->right, i, val, m+1, r);
        cur->left = prev->left;
    }
    cur->val = cur->left->val + cur->right->val;
}

int query(int fl, int fr, node *root, int l = 0, int r = n - 1) {
    if(l >= fl && r <= fr) return root->val;
    if(l > fr || r < fl) return 0;
    int m = (l + r) / 2;
    return query(fl, fr, root->left, l, m) + query(fl, fr, root->right, m+1, r);
}

int main() {
    scanf("%d %d",&n, &k);
    
    version[0] = new node();
    build(version[0]);

    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        version[i] = new node();
        node *tmp = new node();
        if(f[a].size() == k) {
            int bad = f[a].front(); f[a].pop();
            update(version[i-1], tmp, bad, 0);
            update(tmp, version[i], i-1, 1);
        } else {
            update(version[i-1], version[i], i-1, 1);
        }
        f[a].push(i-1);
    }

    scanf("%d", &q);
    int last = 0;
    while(q--) {
        int x, y, l, r;
        scanf("%d %d", &x, &y); 
        l = (x + last) % n;
        r = (y + last) % n;
        if(l > r) swap(l, r);
        last = query(l, r, version[r+1]);
        printf("%d\n", last);
    }
}


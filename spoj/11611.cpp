#include <bits/stdc++.h>

using namespace std;

int n, m,a,b;
char c;
const int N = 100005;
struct node {
    int h,e,r;
    node operator + (node a) const {
        a.h += h; a.e += e; a.r += r;
        return a;
    }
    node(){}
    node (int a, int b, int c) {
        h = a; e = b; r = c;
    }
};

node tree[4*N];
int lazy[4*N];

void build (int no, int ind, int l, int r, node val) {
    if(l == r) {
        tree[no] = val;
    }
    else {
        int mid = (l+r+1)/2;
        if(mid <= ind) build(2*no, ind, mid, r, val);
        else build (2*no+1,ind,l,mid-1,val);
        tree[no] = tree[2*no] + tree[2*no+1];
    }

}

void cycle(int no, int k) {
    int foo, bar;
    k %= 3;
    if(k == 1) {
        foo = tree[no].h; bar = tree[no].e;
        tree[no].h = tree[no].r;
        tree[no].e = foo;
        tree[no].r = bar;
    }
    else if(k == 2) {
        foo = tree[no].h; bar = tree[no].e;
        tree[no].h = bar;
        tree[no].e = tree[no].r;
        tree[no].r = foo;
    }
}

void unlazy(int no, int k){
    cycle(no,lazy[no]);
    if(k){
        lazy[2*no] += lazy[no]; lazy[2*no+1] += lazy[no];
    }
    lazy[no] = 0;
}

void update (int a, int b, int l, int r, int no) {
    unlazy(no,l==r);
    if(b < l || a > r) return;
    if(a >= l && b <= r) {
        lazy[no]++;
        unlazy(no,l==r);
        return;
    } 
    update(a,b,l/2,r,2*no);
    update(a,b,l,r/2 - 1,2*no+1);
    tree[no] = tree[2*no] + tree[2*no+1];
}

node query (int a, int b, int l, int r, int no) {
    unlazy(no, l==r);
    if(b < l || a > r) return node(0,0,0);
    if(a >= l && b <= r) {
        return tree[no];
    }
    return query(a,b,l/2,r,2*no) + query(a,b,l,r/2 - 1,2*no+1);
}

int main(){
    while(scanf("%d %d",&n,&m) != EOF) {
        memset(lazy,0,sizeof lazy);
        for(int i = 1; i <= n; i++) {
            build (1,i,1,n,node(1,0,0));
        }
        scanf(" %c %d %d",&c,&a,&b);
        if (c == 'C') {
            node ans = query(a,b,1,n,1);
            printf("%d %d %d\n",ans.h,ans.e,ans.r);
        }
        else
            update(a,b,1,n,1);
    }
}

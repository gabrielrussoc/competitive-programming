#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int a, n, m, tree[4*N], lazy[4*N];

void buildTree (int l, int r, int no, int i, int val){
    if(l == r) 
        tree[no] = val;
    else {
        int mid = (l+r)/2;
        if(mid >= i) buildTree(l, mid, 2*no, i, val);
        else buildTree(mid+1,r, 2*no+1,i,val);
        tree[no] = tree[2*no] + tree[2*no+1];
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a);
        buildTree (0, n-1, 1, i, a);
    }
    for (int i = 1; i < 8; i++) printf("%d ",tree[i]);
    printf("\n");
    for (int i = 0; i < m; i++){
        int q, l, r;
        scanf("%d %d %d",&q,&l,&r);
        l--; r--;
    }

}

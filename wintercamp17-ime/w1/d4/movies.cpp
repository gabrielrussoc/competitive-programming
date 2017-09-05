#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAXN = 1003456;

int m, n;
int prox[MAXN];
ll s[MAXN];
ll cus[MAXN], res[MAXN];
int aux[MAXN];
int mrk[MAXN];

struct arv{
    ll lz, mx, mn;
} tree[4*MAXN];

void build(int idx, int i, int j){
    if(i == j){
        tree[idx].mx = tree[idx].mn = res[i];
        tree[idx].lz = 0;
        return ;
    }
    int m = (i+j)/2; 
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
    tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
}

ll qry(int idx, int i, int j, int l, int r){
    j = min(j, n-1);
    if(i > j) return 0;
    if(i > r || j < l) return 0;
    if(tree[idx].lz != 0){
        ll aux = tree[idx].lz;
        tree[idx].lz = 0;
        if(i != j){
            tree[idx*2].mx += aux;
            tree[idx*2].mn += aux;
            tree[idx*2+1].mn += aux;
            tree[idx*2+1].mx += aux;
            tree[idx*2].lz += aux;
            tree[idx*2+1].lz += aux;
        }
    }       
    if(i >= l && j <= r){
        return tree[idx].mx;
    }
    int m = (i + j)/2;
    return max(qry(idx*2, i, m, l, r),
            qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, int r, ll x){
    j = min(j, n-1);
    if(i > j) return ;
    if(i > r || j < l) return ;
    if(tree[idx].lz != 0){
        ll aux = tree[idx].lz;
        tree[idx].lz = 0;
        if(i != j){
            tree[idx*2].mx += aux;
            tree[idx*2].mn += aux;
            tree[idx*2+1].mn += aux;
            tree[idx*2+1].mx += aux;
            tree[idx*2].lz += aux;
            tree[idx*2+1].lz += aux;
        }
    }       
    if(i >= l && j <= r){
        tree[idx].mn += x;
        tree[idx].mx += x;
        tree[idx].lz += x;
        return ;
    }
    int m = (i + j)/2;
   upd(idx*2, i, m, l, r, x);
   upd(idx*2+1, m+1, j, l, r, x); 
   tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
   tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int a=0;a<n;a++){
        scanf("%lld", s+a);
    }
    for(int a=1;a<=m;a++){
        scanf("%lld", &cus[a]);
        aux[a] = n;
    }
    for(int a=n-1;a>=0;a--){
        prox[a] = aux[s[a]];
        aux[s[a]] = a;
    }
    prox[n] = n;
    res[0] = 0;
    for(int a=0;a<n;a++){
        if(a != 0) res[a] = res[a-1];
        if(mrk[s[a]] == 0){
            res[a] += cus[s[a]];
            mrk[s[a]]++;
        }
        else if(mrk[s[a]] == 1){
            res[a] -= cus[s[a]];
            mrk[s[a]]++;
        }
     //   printf("%d ", res[a]);
    }
   // printf("\n");
    build(1, 0, n-1);
    ll ans = 0;
    for(int a=0;a<n;a++){
        ans = max(ans, qry(1, 0, n-1, a, n-1));       
      //  printf("%d ", ans);
        upd(1, 0, n-1, a+1, prox[a]-1, -cus[s[a]]);
        upd(1, 0, n-1, prox[a], prox[prox[a]]-1, cus[s[a]]);
    }
    printf("%lld\n", ans);
}


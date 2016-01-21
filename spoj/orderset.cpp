#include <bits/stdc++.h>

using namespace std;
typedef int tree;

const int N = 200004;
int x[N], y[N], lc[N], rc[N], sz[N];
int ts;

void update(tree t){
    sz[t] = 1;
    if(lc[t] != -1) sz[t] += sz[lc[t]];
    if(rc[t] != -1) sz[t] += sz[rc[t]];
}

void split(int k, tree t, tree &l, tree &r) {
    if (t == -1) l = r = -1;
    else if(k <= x[t]) split(k, lc[t], l, lc[t]), r = t;
    else split(k, rc[t], rc[t],r), l = t;
    update(t);
}

void merge(tree &t, tree l, tree r){
    if(l == -1 || r == -1) t = l == -1 ? r : l;
    else if(y[l] < y[r]) merge(lc[r],l, lc[r]), t = r;
    else merge(rc[l], rc[l], r), t = l;
    update(l); update(r);
}

bool find(int k, tree t){
    if(t == -1) return 0;
    if(x[t] == k) return 1;
    if(x[t] > k) return find(k, lc[t]);
    else return find(k, rc[t]);
}

void insert (int k, tree &t){
    if(find(k,t)) return;
    int l, r;
    x[ts] = k; lc[ts] = rc[ts] = -1;
    split(k, t, l, r);
    merge(t, l, ts++);
    merge(t, t, r);
}

void erase (int k, tree &t){
    if(!find(k,t)) return;
    int l,r,l2,r2;
    split(k,t,l,r);
    split(k+1,r,l2,r2);
    merge(t, l, r2);
}

int count(int k, tree t){
    int l, r, ret;
    split(k, t, l, r);
    ret = l != -1 ? sz[l] : 0;
    merge(t,l,r);
    return ret;
}

int kth(int k, tree t){
    int qe = lc[t] != -1 ? sz[lc[t]] : 0;
    if(qe + 1 == k) return x[t];
    else if (qe > k-1) return kth(k, lc[t]);  
    return kth(k - qe - 1, rc[t]);
}

int main() {
    int ct = -1, q, k;
    char c;
    srand(time(NULL));
    scanf("%d",&q);
    for(int i = 0; i < q; i++) y[i] = i;
    random_shuffle(y,y+q);
    for(int i = 0; i < q; i++) {
        scanf(" %c %d", &c, &k);
        if(c == 'I') insert(k, ct);
        else if(c == 'D') erase(k, ct);
        else if(c == 'K'){
            if(ct == -1 || k > sz[ct]) puts("invalid");
            else printf("%d\n",kth(k, ct));
        }
        else printf("%d\n",count(k, ct));
    }
}

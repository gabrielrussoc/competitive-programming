#include <bits/stdc++.h>
using namespace std;

typedef int tree;
const int N = 1e4 + 5;
int r[N], l[N], x[N], y[N], size[N];
int n, m, p;
char c;
int ts = 0;

void update(tree t){
    size[t] = 1;
    if(l[t] >= 0) size[t] += size[l[t]];
    if(r[t] >= 0) size[t] += size[r[t]];
}

void merge (tree &t, tree s, tree b) {
    if (s == -1 || b == -1) t = s == -1 ? b : s;
    else if (y[s] > y[b]) merge(r[s], r[s],b), t = s; 
    else merge(l[b] ,s, l[b]), t = b;
    update(s), update(b);
}

void split (int k, tree t, tree &l, tree &r) {
    if(t == -1) l = r = -1;
    else if(k < x[t]) split(k, ::l[t], l, ::l[t]), r = t;
    else split(k,::r[t],::r[t],r), l = t;
    update(t);
}

void insert (int k, tree &t) {
    x[ts] = k;
    l[ts] = r[ts] = -1;
    int lt, rt;
    split(k, t, lt, rt);
    merge(t,lt,ts++);
    merge(t,t,rt);
}

int query (int k, int t){
    int lt, rt, ret;
    split(k, t, lt, rt);
    ret = lt == -1 ? 0 : size[lt];
    merge(t,lt,rt);
    return ret;
}

int main(){
    srand(time(NULL));
    for(int i = 0; i < N; i++) y[i] = i;
    random_shuffle(y,y+N);
    int ct = -1;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %c %d",&c,&p);
        int lo = p, hi = n;
        while (lo != hi) {
            int mid = lo + (hi-lo)/2;
            if(mid - query(mid, ct) >= p) hi = mid;
            else lo = mid+1;
        }
        if(c == 'D') insert(lo, ct);
        else printf("%d\n",lo);
    }
}


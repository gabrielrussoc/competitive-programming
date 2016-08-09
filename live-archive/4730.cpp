#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
const int K = 2123456;

int t, n, m, a, b;
int x[N], y[N];
char s[13];
int uf[N], wf[N], maxy[N], miny[N];
int bit[K][2];

int query(int idx, int q) {
    int ret = 0;
    for(int i = idx + 2; i > 0; i -= i&-i)
        ret += bit[i][q];
    return ret;
}

void sum (int idx, int val, int q) {
    for(int i = idx+2; i < K; i += i&-i)
        bit[i][q] += val;
}

void add (int a, int b, int val, int q) {
    sum(a,val,q);
    sum(b+1,-val,q);
}

int find(int i) {
    if(i == uf[i]) return i;
    return uf[i] = find(uf[i]);
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return;   
    if(wf[i] > wf[j]) swap(i,j);
    uf[i] = j;
    wf[j] += wf[i]; 
}

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        memset(bit,0,sizeof bit);
        for(int i = 0; i < n; i++) {
            scanf("%d %d",x+i, y+i);
            uf[i] = i;
            wf[i] = 1;
            y[i] *= 2;
            maxy[i] = miny[i] = y[i];
            add(y[i],y[i],1,0);
            add(y[i],y[i],1,1);
        }
        scanf("%d",&m);
        for(int i = 0; i < m; i++) {
            scanf(" %s",s);
            if(strcmp(s, "road") == 0) {
                scanf("%d %d",&a, &b);
                a = find(a); b = find(b);
                if(a == b) continue;
                add(miny[a],maxy[a],-1,0); add(miny[a],maxy[a],-wf[a],1);
                add(miny[b],maxy[b],-1,0); add(miny[b],maxy[b],-wf[b],1);
                join(a,b);
                int x = find(a);
                miny[x] = min(miny[a],miny[b]);
                maxy[x] = max(maxy[a],maxy[b]);
                add(miny[x],maxy[x],1,0);
                add(miny[x],maxy[x],wf[x],1);
            } else {
                double c;
                scanf("%lf",&c);
                printf("%d %d\n",query(2*c,0),query(2*c,1));
            }
        }
    }
}

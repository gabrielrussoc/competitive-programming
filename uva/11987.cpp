#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100004;
ll uf[2*N], wf[2*N], sf[2*N];
int n, m;

ll find(int i){
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join (int i, int j){
    i = find(i); j = find(j);
    if (i == j) return;
    if (wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    sf[j] += sf[i];
    uf[i] = j;
}

int main(){
    while(scanf("%d %d",&n,&m) != EOF){
        for(int i = 1; i <= n ; i++) {
            uf[i+N] = uf[i] = i+N, sf[i+N] = i, wf[i+N] = 1;
        }
        ll c,p,q;
        for(int i = 0; i < m; i++){
            scanf("%lld",&c);
            if (c == 1){
                scanf("%lld %lld",&p,&q);
                join (p,q);
            } else if (c == 2) {
                scanf("%lld %lld",&p,&q);
                int fp, fq;
                fp = find(p); fq = find(q);
                if (fq != fp){
                    uf[p] = fq;
                    sf[fp] -= (ll) p;
                    sf[fq] += (ll) p;
                    wf[fp]--;
                    wf[fq]++;
                }
            } else {
                scanf("%lld",&p);
                p = find(p);
                printf("%lld %lld\n",wf[p],sf[p]);
            }
        }
    }
}

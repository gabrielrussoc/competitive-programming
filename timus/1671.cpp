#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +5;

int n,m,q, uf[N], wf[N], del[N], go[N], qr[N];
int edge[N][2];

int find(int i){
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

int join(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return 0;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
    return 1;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n; i++){
        uf[i] = i;
        wf[i] = 1;
    }
    int a,b;
    for(int i = 0; i < m; i++)
        scanf("%d %d",&edge[i+1][0],&edge[i+1][1]);
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d",&a);
        del[a]++;
        qr[i] = a;
    }
    int ans = n;
    for(int i = 1; i <= m; i++)
        if(!del[i]) ans -= join(edge[i][0],edge[i][1]);
    
    for(int i = q-1; i >= 0; i--){
        go[i] = ans;
        ans -= join(edge[qr[i]][0],edge[qr[i]][1]);
    }
    for(int i = 0; i < q; i++) printf("%d%c",go[i],i == q-1 ? '\n' : ' ');
}

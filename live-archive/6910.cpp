#include <bits/stdc++.h>
#define for_test(t,tc) int t; scanf("%d",&t); for(int tc=1; tc <= t; tc++)
using namespace std;

const int N = 20004;

struct q {
    char c;
    int a,b;
} v[N];

int n, k, in[N], ans[N], uf[N], wf[N], rem[N];

int find(int i){
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join(int i, int j){
    i = find(i); j = find(j);
    if (i == j) return;
    if (wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

int main(){
    for_test(t,tc){
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++){
            rem[i] = 0;
            uf[i] = i;
            wf[i] = 1;
            scanf("%d",&in[i]);
            in[i]--;
        }
        for(int i = 0; i < k; i++){
            scanf(" %c",&v[i].c);
            if (v[i].c == 'C'){
                scanf("%d",&v[i].a);
                v[i].a--;
                rem[v[i].a]++;
            } else {
                scanf("%d %d",&v[i].a,&v[i].b);
                v[i].a--;
                v[i].b--;
            }
        }
        for(int i = 0; i < n; i++)
            if(!rem[i] && in[i] != -1){
                join(i,in[i]);
            }

        int j = 0;
        for(int i = k-1; i >= 0; i--) {
            if(v[i].c == 'C'){
                rem[v[i].a]--;
                if(!rem[v[i].a] && in[v[i].a] != -1) 
                    join (v[i].a,in[v[i].a]);
            }
            else {
                if(find(v[i].a) == find(v[i].b)) ans[j++] = 1;
                else ans[j++] = 0;
            }
        }
        printf("Case #%d:\n",tc);
        for(int i = j-1; i >= 0; i--) printf("%s\n",ans[i] == 1 ? "YES" : "NO");

    }
}

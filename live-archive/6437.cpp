#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 205;
int uf[N], wf[N], pwr[N];

int find (int i){
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
    int x = pwr[i] || pwr[j];
    pwr[i] = x;
    pwr[j] = x;
}

int main(){
    int t,tc=1;
    scanf("%d",&t);
    while (t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i = 0; i <= n; i++){
            wf[i] = 1; uf[i] = i; pwr[i] = 0;  
        }
        priority_queue<pair<int,pii> > q;
        for(int i = 0; i < k; i++){
            int p;
            scanf("%d",&p);
            pwr[p] = 1;
        }
        for(int i = 0; i < m; i++){
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            q.push(mp(-w,pii(a,b)));
        }
        int ans = 0;
        while(q.size()){
            pii edge = q.top().second;
            int w = -q.top().first;
            q.pop();
            int a = edge.first;
            int b = edge.second;
            if((find(a) != find(b)) && !(pwr[find(a)]&&pwr[find(b)])){
                join(a,b);
                ans += w;
            }
        }
        printf("Case #%d: %d\n",tc++,ans);
    }
}

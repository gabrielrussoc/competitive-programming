#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
const int N = 110;
int uf[N];
int wf[N];

int n, m;

int find (int i) {
    if (uf[i] == i) return i;
    return uf[i] = find (uf[i]);
}

void join (int i, int j){
    if(i == j) return;
    i = find (i); j = find (j);    
    if (wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

int main(){
    int tc = 1,a,b,w;
    while (scanf("%d %d",&n,&m) && n){
        for(int i = 1; i <= n; i++) uf[i] = i, wf[i] = 1;
        priority_queue<pair<int,pii> > q;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d",&a,&b,&w);
            if (a > b) swap (a,b);
            q.push(mp(-w,pii(a,b)));
        }
        vector<pii> ans;
        while (q.size()){
            pii edge = q.top().second;
            q.pop();
            if(find(edge.first) != find(edge.second)){
                join (edge.first,edge.second);
                ans.push_back(edge);
            }
        }
        printf("Teste %d\n",tc++);
        for (int i = 0; i < ans.size(); i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
        printf("\n");
    }
}

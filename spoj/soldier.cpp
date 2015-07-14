#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int m[8][1004][103];
vector<pair<int,int> > v[109];


int pd(int k, int t, int i){

    if(t < 0) return 0;
    if(k == 7) return INT_MAX;
    if(i >= v[k].size()) return 0;
    if(m[k][t][i] != -1) return m[k][t][i];
    
    int ans = max(pd(k,t,i+1),min(v[k][i].second,pd(k+1,t-v[k][i].first,0)));
    m[k][t][i] = ans;
    return ans;
}


int main(){

    int n,t;
    memset(m,-1,sizeof m);
    scanf("%d %d",&n,&t);
    
    for(int i = 0; i < n; i++){
        int k,p,q;
        scanf("%d %d %d",&k,&p,&q);
        v[k].pb(make_pair(p,q));
    }
    
    int ans = pd(1,t,0);
    
    printf("%d\n",ans);
}

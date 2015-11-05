#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int t,n;
int M[250];
vector<int> adj[250];
int vis[250];

bool temAumento (int a) {
    for (int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];
        if(vis[b]) continue;
        vis[b] = 1;
        if (M[b] == -1 || temAumento(M[b])){
            M[a] = b;
            M[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       for(int i = 0; i < 240; i++){
           adj[i].clear();
           M[i] = -1;
       }

       int a,b;
       for(int i = 0; i < n; i++){
          scanf("%d %d",&a,&b);
          b += 120;
          adj[a].pb(b);
          adj[b].pb(a);
       }
       int ans = 0;
       while(1){
           int i;
           for(int j = 0; j < 240; j++) vis[j] = 0;
           for(i = 0; i < 120; i++){
               if(M[i] == -1 && temAumento(i)){
                   ans++;
                   break;
               }
           }
           if(i == 120) break;
       }
       printf("%d\n",ans);
    }
}

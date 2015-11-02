#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int M[250], n, m;
int vis[250], v[250];
vector<int> adj[250];

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

int main() {
    int t, tc = 1;
    scanf("%d",&t);
    while(tc <= t){
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",&v[i]);
        scanf("%d",&m);
        for(int i = n; i < n+m; i++) scanf("%d",&v[i]);

        for(int i = 0; i < n+m; i++) {
            adj[i].clear();
            M[i] = -1;
        }
        
        for(int i = 0; i < n; i++)
            for(int j = n; j < n+m; j++)
                if(v[i] && v[j] % v[i]){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
        int ans = 0;
        while(1){
            int i;
            for(int i = n; i < n+m; i++) vis[i] = 0;
            for(i = 0; i < n ; i++){
                if(M[i] == -1 && temAumento(i)){
                    ans++;
                    break;   
                }
            }
            if(i == n) break;
        }
        printf("Case %d: %d\n",tc++,m+n-ans);
    }
}

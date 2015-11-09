#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int v[505];
vector<int> adj[505];
int M[505];
int vis[505];

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
    int n,k;
    while(scanf("%d %d",&n,&k) && n){
        for(int i = 0; i < n; i++){
            scanf("%d",v+i);
            M[i] = -1;
            adj[i].clear();
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(abs(v[i]-v[j]) <= k && abs(v[i]-v[j])&1){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        int ans = 0;
        while(1){
            int i;
            for(int j = 0; j < n; j++) vis[j] = 0;
            for(i = 0; i < n; i++){
                if(v[i]&1 && M[i] == -1 && temAumento(i)){
                    ans++;
                    break;
                }
            }
            if(i == n) break;
        }
        printf("%d\n",ans);
    }
}

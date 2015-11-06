#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int k,p,t,s,c;
int v[405][2];
int tx[205][2];
vector<int> adj[650];
int vis[650];
int M[650];

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
    scanf("%d",&k);
    while(k--){
        scanf("%d %d %d %d",&p,&t,&s,&c);
        for(int i = 0; i < p+t; i++){
            adj[i].clear();
            M[i] = -1;
        }
        for(int i = 0; i < p; i++)
            scanf("%d %d",&v[i][0],&v[i][1]); 
        for(int i = 0; i < t; i++)
            scanf("%d %d",&tx[i][0],&tx[i][1]); 

        for(int i = 0; i < p; i++){
            for(int j = 0; j < t; j++){
                if((double) 200*(abs(v[i][0]-tx[j][0]) + abs(v[i][1]-tx[j][1]))/s <= c){
                    adj[i].pb(p+j);
                    adj[j+p].pb(i);
                }
            }
        }
        int ans = 0;
        while(1){
            int i;
            for(int j = 0; j < p+t; j++) vis[j] = 0;
            for(i = 0; i < p; i++){
                if(M[i] == -1 && temAumento(i)){
                    ans++;
                    break;
                }
            }
            if(i == p) break;
        }
        printf("%d\n",ans);
    }
}

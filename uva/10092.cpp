#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int k,p;
int v[25], st[25];
vector<int> adj[1500];
int M[1500];
int vis[1500];

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
    while(scanf("%d %d",&k,&p) && k){
        for(int i = 0; i < k; i++) scanf("%d",v+i);
        st[0] = 0;
        for(int i = 1; i < k; i++) st[i] = st[i-1]+v[i-1];
        int prob = st[k-1]+v[k-1];
        for(int i = 0; i < prob+p; i++){
            adj[i].clear();
            M[i] = -1;
        }
        for(int i = 0; i < p; i++){
            int n;
            scanf("%d",&n);
            for(int j = 0; j < n; j++){
                int x; 
                scanf("%d",&x);
                x--;
                for(int h = st[x]; h < st[x]+v[x]; h++){
                    adj[h].pb(prob);
                    adj[prob].pb(h);
                }
            }
            prob++;
        }
        int ans = 0;
        while(1){
            int i;
            for(int j = st[k-1]+v[k-1]; j < prob; j++) vis[j] = 0;
            for(i = 0; i < st[k-1]+v[k-1]; i++){
                if(M[i] == -1 && temAumento(i)){
                    ans++;
                    break;
                }
            }
            if(i == st[k-1]+v[k-1]) break;
        }
        if(ans == st[k-1]+v[k-1]){
            printf("1\n");
            for(int i = 0; i < k; i++){
                for(int j = st[k-1]+v[k-1]; j < prob; j++){
                    if(M[j] >= st[i] && M[j] < st[i] + v[i]) printf("%d ",j-st[k-1]-v[k-1]+1);
                }
                printf("\n");
            }
        }
        else printf("0\n");
    }
}

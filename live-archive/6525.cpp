#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<int> adj[20005];
char g[105][105];
int M[20005];
int vis[20005];
int k,l;
int color[105][105];
int color2[105][105];

void pinta (int i,int j){
    if(i > n || g[i][j] == 'X') return;
    color[i][j] = k;
    pinta(i+1,j);
}

void pinta2 (int i,int j){
    if(j > n || g[i][j] == 'X') return;
    color2[i][j] = l;
    pinta2(i,j+1);
}
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
    while (scanf("%d",&n) != EOF){
        for(int i = 0; i < n*n; i++){
            adj[i].clear();
            M[i] = -1;
        }
        k = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf(" %c",&g[i][j]);
                color[i][j] = -1;
                color2[i][j] = -1;
            }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(color[i][j] == -1 && g[i][j] != 'X'){
                    pinta(i,j);
                    k++;
                }
            }
        }
        l = k;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(color2[i][j] == -1 && g[i][j] != 'X'){
                    pinta2(i,j);
                    l++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] != 'X'){
                    adj[color[i][j]].pb(color2[i][j]);
                    adj[color2[i][j]].pb(color[i][j]);
                }
            }
        }
        int ans = 0;
        while(1){
            int i;
            for(int j = 0; j < l; j++) vis[j] = 0;
            for(i = 0; i < k; i++){
                if(M[i] == -1 && temAumento(i)){
                    ans++;
                    break;
                }
            }
            if(i == k) break;
        }
        printf("%d\n",ans);
        
    }
}

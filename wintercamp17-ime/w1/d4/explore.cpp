#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAXN = 1123, MAXNODE = MAXN*MAXN;

int n, m;

char M[MAXN][MAXN];
int solved[MAXN*MAXN];
int mrk[MAXNODE], cic[MAXNODE];

vector<int> und[MAXN*MAXN], adj[MAXN*MAXN];
int idx = 1;

int ind(int i, int j){
    return i*m + j;
}

void add(int i, int j){
    adj[i].pb(j);
    und[i].pb(j);
    und[j].pb(i);
}

int pai[MAXNODE];
int dist[MAXNODE];

vector<int> v;

bool isBlack(int u){
    int i = u/m;
    int j = u%m;
    return isupper(M[i][j]);
}

int tam;

void acha(int u, int p, int d){
    mrk[u] = 1;
    pai[u] = p;
    dist[u] = d;
    for(int nxt: adj[u]){
        if(!mrk[nxt]){
           acha(nxt, u, d+1); 
        }
        else{
            int uu = u;
            tam = 0;
            while(uu != nxt){
                tam++;
                cic[uu] = idx;
                uu = pai[uu]; 
            }
            tam++;
            cic[nxt] = idx;
        }
    }
}

int tot;

void pegaB(int u, int p){
    solved[u] = 1; 
    if(isBlack(u))
        v.pb(u);
    for(int nxt: und[u]){
        if(solved[nxt]) continue;
        pegaB(nxt, u);
    }
}

int prox[MAXNODE], vis[MAXNODE], dis[MAXNODE];

int go(int u, int o){
    if(vis[u]) {
        prox[o] = prox[u];
        return dis[u];
    }
    vis[u] = true;

    if(cic[u] != 0){
        prox[u] = dist[u];
        return 0;
    }
    dis[u] = 1 + go(adj[u][0], o);
    prox[u] = prox[adj[u][0]];
    return dis[u];
}


vector<int> res[3];

void solve(int u){
    acha(u, u, 0);
    idx++;
    v.clear();
    pegaB(u, u);
    int ans = min((int)v.size(), tam);
    tot += ans;
    //printf("res %d\n", ans);
    int first = 10000000;
    //printf("%d %d %d\n", u/m + 1, u%m + 1, first);
    res[0].pb(u/m + 1);
    res[1].pb(u%m + 1);
    res[2].pb(first);
    for(int i=1;i<ans;i++){
        int d = go(v[i], v[i]); 
      //  printf("prox %d d %d\n", prox, d);
        int tempo = prox[v[i]] + i - d;
        //printf("%d %d %d\n", v[i]/m + 1, v[i]%m + 1, first + tempo);  
        res[0].pb(v[i]/m + 1);
        res[1].pb(v[i]%m + 1);
        res[2].pb(first + tempo);
    } 
}

int main() {
    scanf("%d %d", &n, &m);
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]); 
            char c = tolower(M[a][b]);
            if(c == 'w')
                add(ind(a, b), ind(a, b-1));
            else if(c == 'e') 
                add(ind(a, b), ind(a, b+1));
            else if(c == 'n')
                add(ind(a, b), ind(a-1, b));
            else
                add(ind(a, b), ind(a+1, b));
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            if(isupper(M[a][b]) && !solved[ind(a, b)])
                solve(ind(a, b)); 
        }
    }
    printf("%d\n", (int)res[0].size());
    for(int i =0;i < res[0].size(); i++){
        printf("%d %d %d\n", res[0][i], res[1][i], res[2][i]);
    }

}


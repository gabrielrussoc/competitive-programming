#include<bits/stdc++.h>
using namespace std;

int n;
char line[1000];
int es, t, turn = 0;
int to[100*100],nx[100*100],head[205];
int p[205], low[205], visi[205], disc[205], cv[205];
int m[105][105];

void dfs(int u){
    int child = 0;
    visi[u] = turn;
    disc[u] = low[u] = t++;
    for(int e = head[u]; e > 0; e = nx[e]){
        if(visi[to[e]] != turn){
            child++;
            p[to[e]] = u;
            dfs(to[e]);
            low[u] = min(low[u],low[to[e]]);
            if(!p[u] && child > 1) cv[u] = turn;
            if(p[u] && low[to[e]] >= disc[u]) cv[u] = turn;
        } else if(to[e] != p[u]) low[u] = min(low[u], disc[to[e]]);
    }
}


int main(){
    while(scanf("%d",&n) && n){
        getchar();
        int u, v;
        t = es = 1;
        turn++;
        memset(p,0,sizeof p);
        memset(head,0,sizeof head);
        while(scanf(" %[^\n]",line) && line[0] != '0'){
            char *tmp;
            tmp = strtok(line," ");
            u = atoi(tmp);
            while((tmp = strtok(NULL," ")) != NULL){
                v = atoi(tmp);
                if(m[u][v] != turn){
                    to[es] = v; nx[es] = head[u]; head[u] = es++;
                    to[es] = u; nx[es] = head[v]; head[v] = es++;     
                }
                m[u][v] = m[v][u] = turn;
            }
        }
        dfs(1);
        int ans = 0;
        for(int i = 0; i < 105; i++) ans += (cv[i] == turn);
        printf("%d\n",ans);
    }
}

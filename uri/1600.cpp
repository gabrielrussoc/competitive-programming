#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
int n, m;
char g[30][30];
int door[30][30];
int d[30][30][34][30][30];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};

void fill(){
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            g[i][j] = '*';

    memset(door,-1,sizeof door);

    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= m+1; j++)
            for(int k = 0; k < 34; k++)
                for(int l = 0; l <= n+1; l++)
                    for(int p = 0; p <= m+1; p++)
                        d[i][j][k][l][p] = INT_MAX;
}

struct pct {
    pii cat, box;
    int open;
    pct(){}
    pct(pii a, pii b, int c) : cat(a), box(b), open(c) {}
};

void bfs(pct st) {
    queue<pct> q;
    q.push(st);
    d[st.cat.ff][st.cat.ss][st.open][st.box.ff][st.box.ss] = 0;
    while(q.size()){
        pct at = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            pct nxt;
            nxt = pct(pii(at.cat.ff+vx[k],at.cat.ss+vy[k]),pii(at.box.ff,at.box.ss),at.open);
            if(door[nxt.cat.ff][nxt.cat.ss] != -1) nxt.open |= (1 << door[nxt.cat.ff][nxt.cat.ss]);
            if(g[nxt.cat.ff][nxt.cat.ss] != '*'){
                if(nxt.cat != at.box){
                    if(d[nxt.cat.ff][nxt.cat.ss][nxt.open][nxt.box.ff][nxt.box.ss] > d[at.cat.ff][at.cat.ss][at.open][at.box.ff][at.box.ss] + 1){    
                        d[nxt.cat.ff][nxt.cat.ss][nxt.open][nxt.box.ff][nxt.box.ss] = d[at.cat.ff][at.cat.ss][at.open][at.box.ff][at.box.ss] + 1;
                        q.push(nxt);        
                    }           
                } else { 
                    nxt.box.ff += vx[k]; nxt.box.ss += vy[k];
                    if(door[nxt.box.ff][nxt.box.ss] != -1 && !(at.open&(1<<door[nxt.box.ff][nxt.box.ss]))) continue;
                    if(d[nxt.cat.ff][nxt.cat.ss][nxt.open][nxt.box.ff][nxt.box.ss] > d[at.cat.ff][at.cat.ss][at.open][at.box.ff][at.box.ss] + 1){    
                        d[nxt.cat.ff][nxt.cat.ss][nxt.open][nxt.box.ff][nxt.box.ss] = d[at.cat.ff][at.cat.ss][at.open][at.box.ff][at.box.ss] + 1;
                        q.push(nxt);        
                    }           
                }
            }
        }

    }

}

int main(){
    while (scanf("%d %d",&n,&m) != EOF){
        fill();
        pii gato, box,tgt;
        int k = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j] == 'j')
                    gato = pii(i,j);
                if(g[i][j] == 'b')
                    box = pii(i,j);
                if(g[i][j] == '#') 
                    door[i][j] = k++;
                if(g[i][j] == 'x')
                    tgt = pii(i,j);
            }
        bfs(pct(gato,box,0));
        int ans = INT_MAX, ansp = 10;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 34; j++)
                if(__builtin_popcount(j) <= ansp && d[tgt.ff+vx[i]][tgt.ss+vy[i]][j][tgt.ff][tgt.ss] < ans){
                    ansp = __builtin_popcount(j);
                    ans = d[tgt.ff+vx[i]][tgt.ss+vy[i]][j][tgt.ff][tgt.ss];
                }
        }
        if(ans == INT_MAX) printf("-1\n");
        else printf("%d %d\n",ansp,ans);
    }   
}

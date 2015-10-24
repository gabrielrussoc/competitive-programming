#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
int n, m;
char g[30][30];
int door[30][30];
int d[30][30][20][30][30];
int nx[] = {1,-1,0,0};
int ny[] = {0,0,1,-1};

void fill(){
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            g[i][j] = '*';

    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            for(int k = 0; k < 20; k++)
                for(int l = 0; l < 30; l++)
                    for(int m = 0; m < 30; m++)
                        d[i][j][k][l][m] = INT_MAX;
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
            nxt = pct(pii(st.cat.ff+vx[k],st.cat.ss+vy[k]),pii(st.box.ff,st.box.ss),open);
            if(g[nxt.cat.ff][nxt.cat.ss] != '*'){
                if(nxt.cat != at.box){
                        
                }
            }
        }

    }

}

int main(){
    while (scanf("%d %d",&n,&m) != EOF){
        fill();
        pii gato, box;
        open = 0;
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
            }
        bfs(pct(gato,box,0));
    }   
}

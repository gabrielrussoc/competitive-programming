#include <bits/stdc++.h>
using namespace std;
typedef struct triple {
    int ff,ss,tt;
} tii;
typedef pair<int,int> pii;
int vx[] = {0,0,1,-1};
int vy[] = {1,-1,0,0};
int d[105][105][150];
char g[105][105];
tii st,end;

triple mt(int a, int b, int c){
    triple x;
    x.ff = a, x.ss = b, x.tt = c;
    return x;
}

int let(int i, int j){
    int k = 0;
    if(islower(g[i][j])) k = (1 << (g[i][j] -'a'));
    return k;
}

int go(int i, int j, int bit){
    int k = 1;
    if(isupper(g[i][j])) k = (1 << (g[i][j]-'A')) & bit;
    return k; 
}

void bfs(){
    queue<tii> q;
    q.push(st);
    d[st.ff][st.ss][st.tt] = 0;
    while(q.size()){
        tii at = q.front();
        q.pop();
        int w = d[at.ff][at.ss][at.tt];
        at.tt |= let(at.ff,at.ss);
        d[at.ff][at.ss][at.tt] = w;
        for(int k = 0; k < 4; k++){
            int nx = at.ff + vx[k];
            int ny = at.ss + vy[k];
            if(d[nx][ny][at.tt] > d[at.ff][at.ss][at.tt] + 1 && (go(nx,ny,at.tt)) && g[nx][ny] != '#'){
                d[nx][ny][at.tt] = d[at.ff][at.ss][at.tt] + 1;
                q.push(mt(nx,ny,at.tt));
            }
        }
    }

}

int main(){
    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            for(int k = 0; k < 150; k++)
                d[i][j][k] = INT_MAX;

    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            g[i][j] = '#';

    char c;
    int i, j;
    i = j = 1;
    pii end;
    while((c = getchar()) != EOF){
        if(c == '@') st = mt(i,j,0);
        if(c == '*') end = pii(i,j);
        if(c == '\n') i++, j = 1;
        else g[i][j++] = c;
    }
    bfs();
    int ans = INT_MAX;
    for(int i = 0; i < 150; i++)
        ans = min(ans,d[end.first][end.second][i]);
    if(ans != INT_MAX) printf("%d\n",ans);
    else printf("--\n");
}

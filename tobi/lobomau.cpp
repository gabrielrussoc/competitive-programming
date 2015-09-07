#include <cstdio>

char g[260][260];
bool seen[260][260];
int w, s, totw, tots;
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};

void dfs(int i, int j){
    if(seen[i][j] || g[i][j] == '#') return;
    if(g[i][j] == 'k') s++;
    if(g[i][j] == 'v') w++;
    seen[i][j] = true;
    for(int p = 0; p < 4; p++)
        dfs(i+vx[p],j+vy[p]);
}

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n+2; i++)
        for(int j = 0; j < m+2; j++)
            g[i][j] = '#', seen[i][j] = false;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf(" %c",&g[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            w = s = 0;
            dfs(i,j);
            if(w >= s) totw += w;
            else tots += s;
        }


    printf("%d %d\n",tots,totw);

}

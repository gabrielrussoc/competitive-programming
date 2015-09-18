#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int,int>

using namespace std;

int g[55][55];
bool seen[55][55];
int w,h, px,py;
int ans;
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};

void dfs(int i, int j){
    if(g[i][j] == -1) return;
    if(seen[i][j]) return;
    seen[i][j] = true;
    ans += g[i][j];
    for(int k = 0; k < 4; k++)
        if(g[i+vx[k]][j+vy[k]] == -2) return;
    for(int k = 0; k < 4; k++)
        dfs(i+vx[k],j+vy[k]);
}

int main(){
    while(scanf("%d %d",&h,&w) != EOF){
        for(int i = 0; i < w+2; i++)
            for(int j = 0; j < h+2; j++)
                g[i][j] = -1, seen[i][j] = false;

        char c;
        for(int i = 1; i <= w; i++){
            for(int j = 1; j <= h; j++){
                scanf(" %c",&c);
                if(c == '#') g[i][j] = -1;       
                else if(c == 'T')g[i][j] = -2;
                else if(c == 'P') px = i, py = j, g[i][j] = 0;
                else if(c == 'G') g[i][j] = 1;
                else g[i][j] = 0;
            }    
        }
        ans = 0;
        dfs(px,py);
        printf("%d\n",ans);
    }
}

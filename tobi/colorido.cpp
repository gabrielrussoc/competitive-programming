#include <cstdio>
#include <stack>
#include <climits>
#include <algorithm>
#include <utility>
#define inf INT_MAX
#define mp  make_pair
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int vx[] = {1,1,1,0,0,-1,-1,-1};
int vy[] = {1,-1,0,1,-1,1,-1,0};

int n,m,k;
pii ini;
int grid[205][205];

int solve(pii ini){
    stack<pii> p;
    p.push(ini);
    grid[ini.ff][ini.ss] = -1;
    int ans = 0;

    while(p.size()){
        pii at = p.top();
        p.pop();
        ans++;

        for(int i = 0; i < 8; i++){
            int nx, ny;
            nx = at.ff + vx[i];
            ny = at.ss + vy[i];
            if(grid[nx][ny] > grid[at.ff][at.ss]){
                p.push(mp(nx,ny));
                grid[nx][ny] = -1;
            }
        }
    }
    return ans;
}

void show(){
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++)
            printf("%2d ",grid[i][j]);
        printf("\n");
    }
}


int main(){
    scanf("%d %d %d %d %d",&n,&m,&ini.ff,&ini.ss,&k);

    for(int i = 0; i < n+2; i++)
        for(int j = 0; j < m+2; j++)
            grid[i][j] = -1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            grid[i][j] = inf;

    int x,y;
    for(int i = 0; i < k; i++){
        scanf("%d %d",&x,&y);
        grid[x][y] = -1;
    }
    int ans = solve(ini);
    //show();
    printf("%d\n",ans);

}
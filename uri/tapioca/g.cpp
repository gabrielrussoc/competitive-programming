#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int v[25][25][1005];
int memo[25][25][1005];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};


int dp(int i, int j, int t){
    if(i > 20 || i < 0 || j > 20 || j < 0 || t > 1000) return 0;
    int &k = memo[i][j][t];
    if (k != -1) return k;
    int ans = v[i][j][t];
    int y = 0;
    for(int p = 0; p < 4; p++){
       y = max(y,dp(i+vx[p],j+vy[p],t+1));
    }
    y = max(y,dp(i,j,t+1));
    return k = ans+y;
}


int main(){
    memset(v,0,sizeof v);
    memset(memo,-1,sizeof memo);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int x,y,t;
        scanf("%d %d %d",&x,&y,&t);
        v[x][y][t]++;
    }
    int ans = dp(6,6,0);

     printf("%d\n",ans);
}

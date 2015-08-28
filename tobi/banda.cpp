#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int v[105][105];

int main(){

    memset(v,0,sizeof v);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        v[x][y] = v[y][x] = z;
    }
    int maxi = 0;
    int a = 1, b = 2, c = 3;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            for(int k = j+1; k <= n; k++){
                int ans = v[i][k] + v[i][j] + v[j][k];
                if(ans >  maxi){
                    maxi = ans;
                    a = i;
                    b = j;
                    c = k;
                }
            }

    printf("%d %d %d\n",a,b,c);
}
  
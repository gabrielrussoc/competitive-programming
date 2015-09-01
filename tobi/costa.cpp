#include <cstdio>

char c[1004][1004];

int main(){
    int n,m;
    for(int i = 0; i < 1004; i++)
        for(int j = 0; j < 1004; j++)
            c[i][j] = '.';

    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf(" %c",&c[i][j]);
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(c[i][j] == '#')
                if(c[i+1][j] == '.' || c[i-1][j] == '.' || c[i][j+1] == '.' || c[i][j-1] == '.')
                    ans++;

    printf("%d\n",ans);
}

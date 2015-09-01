#include <cstdio>

using namespace std;

int n,m;

char in[105][105];
bool shot[105][105];
bool s[105][105];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};
bool ans;

void dfs(int i, int j) {
    if(s[i][j] || in[i][j] != '#') return;
    s[i][j] = true;
   
    if(!shot[i][j]) ans = false; 
    for(int k = 0; k < 4; k++)
        dfs(i+vx[k],j+vy[k]);
}

int main(){

    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            shot[i][j] = s[i][j] = false;

    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c",&in[i][j]);
    int k;
    scanf("%d",&k);
    int a,b;
    for(int i = 0; i < k; i++){
        scanf("%d %d",&a,&b);
        shot[a-1][b-1] = true;
    }

    int cont = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            ans = true;
            if(!s[i][j] && in[i][j] == '#'){
                dfs(i,j);
                if(ans) cont++;
            }
        }
    printf("%d\n",cont);
}

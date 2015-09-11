#include <cstring>
#include <set>
#include <cstdio>

using namespace std;
char g[1004][1004];
int seen[1004][1004];
int v[1000006];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,-1,1};
int l,c;
int ans;
int h = 1;
void dfs(int i, int j){
    if(seen[i][j] != 0) return;
    seen[i][j] = h;
    ans++;
    for(int k = 0; k < 4; k++){
        if(g[i+vx[k]][j+vy[k]] == 'n') dfs(i+vx[k],j+vy[k]);
    }
}


int main(){
    memset(seen,0,sizeof seen);
    scanf("%d %d",&l,&c);
    for(int i = 0; i < l+2; i++)
        for(int j = 0; j < c+2; j++)
            g[i][j] = 'b';

    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= c; j++)
            scanf(" %c",&g[i][j]);
    int maxi = -1, bx,by;
    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= c; j++){
            if(g[i][j] == 'n'){
                ans = 0;
                dfs(i,j);
                if(ans != 0) v[h++] = ans;
            }
        }

    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= c; j++){
            if(g[i][j] == '*'){
                int sum = 0;
                set<int> s;
                for(int k = 0; k < 4; k++){
                    if(g[i+vx[k]][j+vy[k]] == 'n'){
                       int r = seen[i+vx[k]][j+vy[k]];
                       if(s.find(r) == s.end()){
                        sum += v[r];
                        s.insert(r);
                       }
                    }
                }
                if(sum > maxi){
                   maxi = sum;
                   bx = i, by = j;
                }
            }
        }
    }
    
    printf("%d,%d\n",bx,by,maxi);
}

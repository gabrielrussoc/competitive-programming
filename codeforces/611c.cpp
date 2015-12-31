#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define ff first
#define ss second
using namespace std;
typedef long long ll;

//////////////0123456789
const int N = 505;
const int modn = 1000000007;

int acc[N][N];
char g[N][N];

int dom (int i, int j){
    int ret = 0;
    if(g[i][j] == '.'){
        if(g[i-1][j] == '.') ret++;
        if(g[i][j-1] == '.') ret++;
    }
    return ret;
}

int ac(int x, int y){
    if(x < 0 || y < 0) return 0;
    return acc[x][y];
}

int vert(int i, int j,int p){
    if(i == 0) return 0;
    int ans = 0;
    for(int k = j; k < j+p; k++)
        if(g[i][k] == '.' && g[i][k] == g[i-1][k]) ans++;
    return ans;
}

int hor(int i, int j, int p){
    if (j == 0) return 0;
    int ans = 0;
    for(int k = i; k < i+p; k++)
       if(g[k][j] == '.' && g[k][j-1] == g[k][j]) ans++;
    return ans;
}

int main (){
    int w,h;
    scanf("%d %d",&h,&w);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            scanf(" %c",&g[i][j]);
    acc[0][0] = 0;
    for(int i = 1; i < w; i++) acc[0][i] += acc[0][i-1] + (g[0][i] == g[0][i-1] && g[0][i] == '.');
    for(int i = 1; i < h; i++) acc[i][0] += acc[i-1][0] + (g[i][0] == g[i-1][0] && g[i][0] == '.');
    for(int i = 1; i < h; i++)
        for(int j = 1; j < w; j++)
            acc[i][j] += acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1] + dom(i,j);
    int q, r1,c1,r2, c2, res;
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        r1--;r2--;c1--;c2--;
        res = ac(r2,c2) - ac(r1-1,c2) - ac(r2,c1-1) + ac(r1-1,c1-1);
        res -= vert(r1,c1,c2-c1+1);
        res -= hor(r1,c1,r2-r1+1);
        printf("%d\n",res);
    }
}

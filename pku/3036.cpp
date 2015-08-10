#include <cstdio>
#include <cstring>

using namespace std;

int memo[100][100][16];

int pd(int x, int y, int s){

    if(s == 0){
        if(x == y && y == 20)
            return 1;
        else
            return 0;
    }

    if(memo[x][y][s] != -1) return memo[x][y][s];

    int ans = pd(x-1,y-1,s-1) + pd(x,y-1,s-1) + pd(x+1,y,s-1) +
    pd(x+1,y+1,s-1) + pd(x,y+1,s-1) + pd(x-1,y,s-1);

    memo[x][y][s] = ans;
    return ans;

    
}

int main(){

    int t,n;
    scanf("%d",&t);
    while(t--){
        memset(memo,-1,sizeof memo);
        scanf("%d",&n);
        printf("%d\n",pd(20,20,n));
    }

}
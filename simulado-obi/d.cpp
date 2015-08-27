#include <cstdio>
#include <cstring>
#include <map>
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int w,D,V;
int d[12];
map<pii,int> memo;

int dp(int n, int l){
    if(l < 0 || n < 0) return 0;
    if(l == 0 && n == 0) return 1;
    if(memo.find(mp(n,l)) != memo.end()) return memo[mp(n,l)];
    int ans = 0; 
    for(int i = 0; i < D; i++){
        ans += dp(n-d[i],l-1);
        if(n != 0 && d[i] != 0)
            if(n%d[i] == 0) ans += dp(n/d[i],l-1); 
    }
    memo[mp(n,l)]= ans;
    return ans;
}


int main(){

    scanf("%d %d",&w,&D);
    for(int i = 0; i < D; i++)
        scanf("%d",&d[i]);

    scanf("%d",&V);
    int vi;
    for(int i = 0; i < V; i++){
        scanf("%d",&vi);
        if(dp(vi,w+1)) printf("Y\n");
        else printf("N\n");
    }    

}


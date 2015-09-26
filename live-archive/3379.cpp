#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[1003][1003];
int v[1003];

int pd(int i, int j){
    if(j < i) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    int ans;

    int r1,r2;
    r1 = v[i];
    if(v[i+1] >= v[j])
        r1 += pd(i+2,j) - v[i+1];
    else
        r1 += pd(i+1,j-1) - v[j];

    r2 = v[j];
    if(v[i] >= v[j-1])
        r2 += pd(i+1,j-1) - v[i];
    else
        r2 += pd(i,j-2) - v[j-1];

    ans = max(r1,r2);
    memo[i][j] = ans;
    return ans;
}

int main(){

    int n,tc = 1;
    while(scanf("%d",&n), n != 0){
        memset(memo,-1,sizeof memo);
        for(int i = 0; i < n; i++)
            scanf("%d",&v[i]);
        int ans = pd(0,n-1);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",tc++,ans);
    }


}

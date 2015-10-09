#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int bit[1003][1003];
int in[N][2];
int dp[N];

int query(int idx, int idy){
    int ans = 0;
    for(int i = idx; i > 0; i -= i&-i)
        for(int j = idy; j > 0; j -= j&-j)
            ans = max(ans,bit[i][j]);
    return ans;
}

void upd(int idx, int idy, int val){
    for(int i = idx; i < 1003; i += i&-i)
        for(int j = idy; j < 1003; j += j&-j)
            bit[i][j] = max(bit[i][j],val);
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        memset(bit,0,sizeof bit);
        scanf("%d",&n);
        int x,y;
        for(int i = 0; i < n; i++){
            scanf("%d %d",&x,&y);
            in[i][0] = x, in[i][1] = y;
        }
        for(int i = 0; i < n; i++){
            dp[i] = 1 + query(in[i][0],in[i][1]);
            upd(in[i][0],in[i][1], dp[i]);
        }
        printf("%d\n",*max_element(dp, dp + n));
    }
}

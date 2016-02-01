#include <bits/stdc++.h>
using namespace std;
const int N = 1600;

int dp[N][N],n;
char s[N];

void show (int i, int j){
    if(i>=j) return;
    int ans = dp[i][j];
    if(s[i] == s[j] && dp[i+1][j-1]+1 == ans) printf("%d %d\n",i+1,j+1), show(i+1,j-1); 
    else
        for(int k = i; k < j; k++)
            if(dp[i][k] + dp[k+1][j] == ans){
                show(i,k), show(k+1,j);
                return;
            }
}

int main(){
    freopen("cable.in","r",stdin);
    freopen("cable.out","w",stdout);
    scanf("%d",&n);
    scanf(" %s",s);
   
    for(int d = 1; d < n; d++)
        for(int i = 0; i < n-d; i++){
            if(s[i] == s[i+d]) dp[i][i+d] = dp[i+1][i+d-1]+1;
            else
                for(int j = i; j < i+d; j++)
                    dp[i][i+d] = max(dp[i][i+d],dp[i][j]+dp[j+1][i+d]);
        }

    printf("%d\n",dp[0][n-1]);
    show(0,n-1);
}

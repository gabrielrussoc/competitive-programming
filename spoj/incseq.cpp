#include <bits/stdc++.h>
using namespace std;

const int MOD = 5000000;
const int ms = 100005;

int bit[55][ms];
int n, K;
int dp[10004][55], v[10004];

void upd(int k, int idx, int val){
    for(int i = idx; i < ms; i += i&-i){
        bit[k][i] += val%MOD;
        bit[k][i] %= MOD;
    }
}

int query(int k, int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i){
        sum += bit[k][i];
        sum %= MOD;
    }
    return sum;
}

int main(){
    scanf("%d %d",&n,&K);
    int ans = 0;
    memset(bit,0,sizeof bit);
    for(int i = 0; i < n; i++)
        scanf("%d",&v[i]);
    for(int i = 0; i < n; i++){
        for(int k = 1; k <= K; k++){
            dp[i][k] = query(k-1,v[i]-1) + 1;
            upd(k,v[i],dp[i][k]);
        }
    }

    printf("%d\n",dp[n-1][K]);
}

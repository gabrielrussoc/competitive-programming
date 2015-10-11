#include <bits/stdc++.h>
using namespace std;

const int MOD = 5000000;
const int ms = 100005;

int bit[55][ms];
int n, K;
int dp[55], v[10004];

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
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
        v[i]++;
    }
    memset(dp,0,sizeof dp);
    for(int i = 0; i < n; i++){
        upd(1,v[i],1);
        for(int k = 2; k <= K; k++){
            int x = query(k-1,v[i]-1);
            dp[k] += x;
            dp[k] %= MOD;
            upd(k,v[i],x);
        }
    }

    printf("%d\n",dp[K]);
}


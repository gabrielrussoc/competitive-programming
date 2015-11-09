#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sum, n;
ll memo1[20][35];
int v[20];
ll memo[20][35][2];


ll dp(int i, int s){
    if(s <= 0) return 0;
    if(i == n) return 1;
    ll &me = memo1[i][s];
    if(me != -1) return me;
    me = 0;
    for(int j = 0; j < 31; j++)
        me += dp(i+1,s-j);
    return me;
}

ll dp2(int i, int s, bool pre){
    if (s == 0) return 1;
    if (s < 0 || i == n) return 0;
    ll &me = memo[i][s][pre];
    if (me != -1) return me;
    me = 0;
    for(int j = 0; j < 31; j++){
        if(pre && j > v[i]) break;
        me += dp2(i+1,s-j,pre && v[i]==j);
    }
    return me;
}

int main(){
    while(scanf("%d",&n) && n){
        ll ans;
        sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",v+i);
            sum += v[i];
        }
        memset(memo1,-1,sizeof memo1);
        ans = dp(0,sum);
        memset(memo,-1,sizeof memo);
        ans += dp2(0,sum,1);
        printf("%lld\n",ans);
    }

}

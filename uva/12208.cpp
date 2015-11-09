#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s;
ll memo[35][35][2];

ll dp(int i, int sum, bool pre){
    if (i == -1) return sum;
    ll &me = memo[i][sum][pre];
    if(me != -1) return me;
    me = 0;
    for(int j = 0; j < 2; j++){
        if(pre && j > !!((1<<i)&s)) break;
        me += dp(i-1,sum + (j==1), pre && (j==(!!((1<<i)&s))));
    }
    return me;
} 

int main(){
    int a,b, tc = 1;
    while(scanf("%d %d",&a,&b) && b){
        memset(memo,-1,sizeof memo);
        s = b;
        ll ans = dp(30,0,1);
        if(a != 0){
            s = a-1;
            memset(memo,-1,sizeof memo);
            ans -= dp(30,0,1);
        }
        printf("Case %d: %lld\n",tc++,ans);
    }
}

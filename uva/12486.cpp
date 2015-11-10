#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[20][20][12][2][2];
char str[24];

ll dp(int i, int sum, int ult, int pre, int f){
    if(str[i] == 0) return sum;
    ll &me = memo[i][sum][ult][pre][f];
    if(me != -1) return me;
    me = 0;
    for(int d = 0; d < 10; d++){
        if(pre && d > str[i]-'0') break;
        int x = f;
        if(d == 4 || (d == 3 && ult == 1)) x = 1;
        me += dp(i+1,x,d,pre && d == str[i]-'0',x);
    }
    return me;
}

int main(){
    ll n;
    while(scanf("%lld",&n) != EOF){
        memset(memo,-1,sizeof memo);
        sprintf(str,"%lld",n);
        printf("%lld\n",n+dp(0,0,0,1,0));
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[12][12][2][2];
char s[15];
int x;

ll dp(int i, int sum, bool pre, bool z){
    if(s[i] == 0) return sum;
    ll &me = memo[i][sum][pre][z];
    if (me != -1) return me;
    me = 0;
    for(int d = 0; d < 10; d++){
        if(pre && d > s[i]-'0') break;
        me += dp(i+1,sum + ((d==x)&(!z)),pre && d==(s[i]-'0'),z && !d);
    }
    return me;
}


int main(){
    int a,b;
    while(scanf("%d %d",&a,&b) && a){
        for(int i = 0; i < 10; i++){
            x = i;
            memset(memo,-1,sizeof memo);
            sprintf(s,"%d",b);
            ll ans = dp(0,0,1,!i);           
            sprintf(s,"%d",a-1);
            memset(memo,-1,sizeof memo);
            ans -= dp(0,0,1,!i);
            printf("%lld%c",ans,i == 9 ? '\n' : ' ');
        }
    }
}

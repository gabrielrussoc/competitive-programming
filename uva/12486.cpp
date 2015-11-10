#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll memo[20][12][2][2];
char str[24];

ll dp(int i, int ult, int pre, int f){
    if(str[i] == 0) return f;
    ll &me = memo[i][ult][pre][f];
    if(me != -1) return me;
    me = 0;
    for(int d = 0; d < 10; d++){
        if(pre && d > str[i]-'0') break;
        int x = f;
        if(d == 4 || (d == 3 && ult == 1)) x = 1;
        me += dp(i+1,d,pre && d == str[i]-'0',x);
    }
    return me;
}

int main(){
    ll n;
    while(scanf("%llu",&n) != EOF){
        ll l, r;
        l = 0; r = 10000000000000000000;
        while(l != r){
            ll mid = l + (r-l)/2;
            memset(memo,-1,sizeof memo);
            sprintf(str,"%llu",mid);
            if (mid-dp(0,0,1,0) >= n) r = mid;
            else l = mid+1;
        }
        printf("%llu\n",l);
    }
}

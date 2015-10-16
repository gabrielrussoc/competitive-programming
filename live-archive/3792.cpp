#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char x[15], w[15];
int n;

ll dp(int i, int f){
    if(i == n) return f^1;
    if(w[i] == '?'){
        if(f) return  dp(i+1,1) + (9-x[i]+'0')*dp(i+1,0);
        else return 10*dp(i+1,0);       
    } else {
        if(f && (w[i]-'0' < x[i]-'0') ) return  0;
        else {
            if(f) return dp(i+1,x[i] == w[i]);
            else return dp(i+1,0);
        }
    }
}

int main(){
    while(1){
        scanf(" %s",w);
        if(w[0] == '#') break;
        scanf(" %s",x);
        n = strlen(x);
        printf("%lld\n",dp(0,1));
    }
}

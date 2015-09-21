#include <bits/stdc++.h>
#define MAX 5000006

using namespace std;
typedef unsigned long long hash;


const hash X = 33;
hash he[MAX], hd[MAX], x[MAX];
char s[MAX];
int t;
int memo[MAX];

int cv (char c){
    return (c-'a'+1);
}

hash calce(int i, int j){
    return (he[j+1] - he[i]*x[j-i+1]);
}

hash calcd(int i, int j){
    return (hd[j+1] - hd[i]*x[j-i+1]);
}

int dp(int i){
    if(i == 0) return 1;
    int &k = memo[i];
    if(k != -1) return k;
    if(calce(0,i) == calcd(t-i-1,t-1)) k = 1 + dp((i-1)/2);
    else k = 0;
    return k;
}

int main(){
    scanf(" %s",s);
    memset(memo, -1, sizeof memo);
    he[0] = hd[0] = 0;
    x[0] = 1;
    t = strlen(s);
    for(int i = 1; i <= t; i++){
        he[i] = he[i-1]*X + cv(s[i-1]);
        hd[i] = hd[i-1]*X + cv(s[t-i]);
        x[i] = X*x[i-1];
    }
    int ans = 0;
    for(int i = 0; i < t; i++){
        ans += dp(i);
    }
    printf("%d\n",ans);

}

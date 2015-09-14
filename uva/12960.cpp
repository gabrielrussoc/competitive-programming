#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

char s[2007];
int v[2007];
pii memo[2007][2007], x;
int n;

pii dp(int i, int j){
    if(i == j) return mp(v[i],1);
    if(i > j) return mp(0,0);
    pii &k = memo[i][j];
    if(k != x) return k;
    pii foo = x;
    if(s[i] == s[j]) {
        foo = dp(i+1,j-1);
        foo.ff += v[i]+v[j];
        foo.ss += 2;
    }
    foo = max(foo,dp(i+1,j));
    foo = max(foo,dp(i,j-1));
    return k = foo;
    
}

int main(){
    x = mp(-1,-1);
    while(scanf(" %s",s) != EOF){
    memset(memo,-1,sizeof memo);
    memset(v,0,sizeof v);
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        v[a-1] = 1;
    }
    pii ans = dp(0,strlen(s) - 1);
    printf("%d\n",ans.second);
    }
}

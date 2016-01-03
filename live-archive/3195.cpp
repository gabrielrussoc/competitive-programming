#include <bits/stdc++.h>
using namespace std;
const int N = 405;

char a[N], b[N], c[N];
int memo[204][204][2],A,B;

int solve (int i, int j, int f){
    if(i > A || j > B) return 0;
    if(a[i] == 0 && b[j] == 0) return f;
    int &me = memo[i][j][f];
    if(me != -1) return me;
    return me = solve(i+1,j, f&(a[i] == c[i+j])) + solve(i,j+1,f&(b[j] == c[i+j]));
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%s %s %s",a,b,c);
        A = strlen(a);
        B = strlen(b);
        memset(memo,-1,sizeof memo);
        int ans = solve(0,0,1);
        printf("Data set %d: %s\n",tc, ans ? "yes" : "no");
    }
}

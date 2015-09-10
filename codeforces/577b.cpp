#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int v[1004];
int in[1000006];
int memo[1003][1003][3];
int n, m;
int dp(int i, int w, int p){
    if(w == 0 && p) return 1;
    if(i == n) return 0;
    int &me = memo[i][w][p];
    if(me != -1) return me;

    if(dp(i+1, (w+in[i])%m, 1))
        return me = 1;
    if(dp(i+1,w, 0)) return me = 1;
    return me = 0;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%d",&in[i]);
    }
    if(n >= m) cout << "YES" << endl;
    else{
        memset(memo,-1,sizeof memo);
        if(dp(0,0,0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
}

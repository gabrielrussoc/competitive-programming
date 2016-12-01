#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, m, ans;
char g[205][205];

bool good(int ti, int tj) {
    if(ti+3 > n) return false;
    if(tj+3 > m) return false;
    for(int k = 0; k < 3; k++) {
        if(g[ti][tj+k] != 't') return false; 
        if(g[ti+k][tj+1] != 't') return false;
    }
    return true;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c",&g[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(good(i,j)) ans++;
    printf("%d\n",ans);
}


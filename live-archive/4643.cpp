#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, m, p, v[133];
int visi[1<<12][1<<12];
int memo[1<<12][1<<12];
int turn;
char t[22];

int dp(int q, int r) {
    if(__builtin_popcount(q) == m) return 0;
    int &me = memo[q][r];
    if(visi[q][r] == turn) return me;
    visi[q][r] = turn;
    int cont = 0;
    for(int i = 0; i < n; i++)
        if((q&v[i]) ==  r) cont++;
    if(cont == 1) return me = 0;
    me = 33;
    for(int i = 0; i < m; i++) {
        int l = 1<<i;
        if(!(q&l)) me = min(me, 1 + max(dp(q|l, r), dp(q|l, r|l)));
    }
    return me;
}

int main() {
    while(scanf("%d %d",&m,&n) && n && m) {
        turn++;
        for(int i = 0; i < n; i++) {
            scanf(" %s",t);
            v[i] = 0;
            p = 1;
            for(int j = m-1; j >= 0; j--) {
                v[i] += (t[j] == '1') * p;
                p *= 2;
            } 
        }
        printf("%d\n",dp(0,0));
    }
}


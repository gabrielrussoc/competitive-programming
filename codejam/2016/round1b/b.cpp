#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;

char s[3][5], s2[5];
int n;
vector<int> ans[3];


void gera(int mask, int g) {
    if(mask & (1 << 0) && mask & (1 << 1) && mask & (1 << 2)) {
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                for(int k = 0; k < 10; k++)
                    ans[g].pb(100*i + 10*j + k);
    }
    else if(mask & (1 << 0) && mask & (1 << 1)) {
        for(int i = 0; i < 10; i++)
            for(int j = 0;j < 10; j++)
                ans[g].pb(100*i + 10*j + s[g][2]-'0');
    }
    else if(mask & (1 << 0) && mask & (1 << 2)) {
        for(int i = 0; i < 10; i++)
            for(int j = 0;j < 10; j++)
                ans[g].pb(100*i + 10*(s[g][1]-'0') + j);
    }
    else if(mask & (1 << 1) && mask & (1 << 2)) {
        for(int i = 0; i < 10; i++)
            for(int j = 0;j < 10; j++)
                ans[g].pb(100*(s[g][0]-'0') + 10*i + j);
    }
    else if(mask & (1 << 0)) {
        for(int i = 0; i < 10; i++)
            ans[g].pb(100*i + 10*(s[g][1]-'0') + s[g][2]-'0');
    }
    else if(mask & (1 << 1)) {
        for(int i = 0; i < 10; i++)
            ans[g].pb(100*(s[g][0]-'0') + 10*i + s[g][2]-'0');
    }
    else if(mask & (1 << 2)) {
        for(int i = 0; i < 10; i++)
            ans[g].pb(100*(s[g][0]-'0') + 10*(s[g][1]-'0') + i);
    }
    else ans[g].pb(atoi(s[g]));
}
char gg[3][5];
int k;
void printa(int g) {
    int w = strlen(gg[g]);
    putchar(' ');
    for(int i = 0; i < k-w; i++) putchar('0');
    printf("%s",gg[g]);
}

int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        ans[0].clear();
        ans[1].clear();
        scanf(" %s %s",s[0], s[1]);
        n = strlen(s[0]);
        k = n;
        while(n < 3) {
            for(int i = n; i > 0; i--)
                s[0][i] = s[0][i-1], s[1][i] = s[1][i-1];
            s[0][0] = s[1][0] = '0';
            n++;
            s[0][n] = s[1][n] = 0;
        }
        int mask = 0;
        for(int i = 0; i < n; i++) if(s[0][i] == '?') mask |= (1 << i);
        gera(mask, 0);
        mask = 0;
        for(int i = 0; i < n; i++) if(s[1][i] == '?') mask |= (1 << i);
        gera(mask,1);
        int dif = inf, c, j;
        for(int x : ans[0])
            for(int y : ans[1]) { 
                if(abs(x-y) < dif){
                    dif = abs(x-y);
                    c = x;
                    j = y;
                }
                else if(abs(x-y) == dif) {
                    if (x < c) c = x;
                    else if (x == c) {
                        if(y < j) j = y;
                    }
                }
            }
        sprintf(gg[0],"%d",c);
        sprintf(gg[1],"%d",j);
        printf("Case #%d:", tc);
        printa(0); printa(1);
        putchar('\n');
    }
}


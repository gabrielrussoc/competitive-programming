#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 10007;
const int I = 504;
int tc, n, p;
int c[N], dp[I][N], acc[I], s[I][N];

int main() {
    scanf("%d", &tc);
    bool blank = false;
    while(tc--) {
        if(blank) putchar('\n');
        blank = true;
        scanf("%d",&n);
        n *= 100;
        p = 0;
        int a;
        while(scanf("%d", &a) && a) {
            c[p++] = a;
        }
        //dp[i][j] => comecando do carro i, quantos consigo colocar se uma lane ja tem j
        //resposta -> dp[0][0]
        //dp[i][j] = max(dp[i+1][j], dp[i+1][j+c[i]]) 
        //dp[i+1][j] so pode se acc[i] + c[i] - j <= n
        //dp[i+1][j+c[i]] so pode se j + c[i] <= n
        //dp[p][i] = 0 para todo i (nao tem carro nenhum pra colocar)
        
        acc[0] = 0;
        for(int i = 0; i < p; i++) acc[i+1] = acc[i] + c[i];
        
        for(int i = 0; i <= n; i++) dp[p][i] = 0;
        for(int i = p - 1; i >= 0; i--) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = 0;
                if(acc[i] - j + c[i] <= n && 1 + dp[i+1][j] > dp[i][j]) {
                    dp[i][j] = 1 + dp[i+1][j];
                    s[i][j] = 0;
                }
                if(j + c[i] <= n && 1 + dp[i+1][j+c[i]] > dp[i][j]) {
                    dp[i][j] = 1 + dp[i+1][j+c[i]];
                    s[i][j] = 1;
                }
            }
        }
        printf("%d\n", dp[0][0]);
        int l = 0;
        for(int i = 0; i < dp[0][0]; i++) {
            puts(s[i][l] ? "port" : "starboard");
            l = s[i][l] ? l + c[i] : l;
        }
    }
}


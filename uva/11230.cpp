#include <bits/stdc++.h>

using namespace std;

int n,m,r,c;
int a[105][105], b[105][105];

int main() {
    while(scanf("%d %d %d %d",&n,&m,&r,&c) && n != 0) {
        memset(b,0,sizeof b);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                char d;
                scanf(" %c",&d);
                a[i][j] = d-'0';
            }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] != b[i][j]){
                    ans++;
                    if(i+r-1 < n && j + c - 1 < m){
                        for(int k = i; k < i+r; k++)
                            for(int l = j; l < j+c; l++)
                                b[k][l] ^= 1;
                    }
                }
            }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != b[i][j]) ans = -1;
            }
        }

        printf("%d\n",ans);

    }
}

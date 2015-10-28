#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, c;
    char v[1005][75];
    while(scanf("%d %d %d",&n,&l,&c) != EOF){
        for(int i = 0; i < n; i++)
            scanf(" %s",v[i]);
        int i = 0, ln = 0, ch = 0;
        int ans = 0;
        while (i < n){
            if(ch + strlen(v[i]) > c){
                ln++;
                if(ln == l){
                    ln = 0;
                    ans++;
                }
                ch = 0;
            }
            ch += strlen(v[i]) +1;
            i++;
        }
        printf("%d\n",ans+1);
    }
}

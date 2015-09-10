#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x, ans = 0;
    scanf("%d %d",&n,&x);
    for(int i = 1; i <= n; i++)
        if(x%i == 0)
           if(x/i <= n) ans++;

    printf("%d\n",ans);
}

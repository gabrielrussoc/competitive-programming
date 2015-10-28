#include <bits/stdc++.h>
using namespace std;

int n;
int v[10004];
int main(){
    while(scanf("%d",&n) != EOF){
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",v+i);
            sum += v[i];
        }
        int ans = 0;
        if(sum%n == 0) {
            sum = sum/n;
            for(int i = 0; i < n; i++)
                ans += abs(v[i]-sum);
            printf("%d\n",ans/2 + 1);
        } else printf("-1\n");
    }
}

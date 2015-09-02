#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int p[20004];
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&p[i]);
        sort(p,p+n);
        int i = 0, j = n-1;
        int ans = 0;
        for(int i = n-3; i >= 0; i -= 3)
            ans += p[i];
        printf("%d\n",ans);
    }
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int n, b, h, w, x;
int p[20], wk[20];

int main(){
    
    while(scanf("%d %d %d %d",&n,&b,&h,&w) != EOF){
        memset(wk,0,sizeof wk);
        for(int i = 0; i < h; i++){
            scanf("%d",p+i);
            for(int j = 0; j < w; j++){
                scanf("%d",&x);
                if(x >= n) wk[i] = 1;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < h; i++)
            if(wk[i])
                if(p[i]*n <= b)
                    ans = min(ans,p[i]*n);

        if(ans != INT_MAX)
            printf("%d\n",ans);
        else
            printf("stay home\n");
    }

}

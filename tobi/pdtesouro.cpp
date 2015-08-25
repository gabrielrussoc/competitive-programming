#include <cstdio>
#include <cstring>
using namespace std;

int v[105];
int m[105][10004];
int n;

int pd(int i, int p){
    if(p == 0) return 1;
    if(i == n || p < 0) return 0;
    int &k = m[i][p];
    if(k != -1) return k;
    
    k = pd(i+1,p-v[i]) + pd(i+1,p);
    return k;
}

int main(){

    int x,y,tc=1;
    while(scanf("%d %d %d",&x,&y,&n) && x != 0 && y != 0 && n != 0){
        int tot = x+y;
        for(int i = 0; i < n; i++){
            scanf("%d",&v[i]);
            tot += v[i];
        }
        memset(m,-1,sizeof m);
        int ans;
        if(tot&1) ans = 0;
        else ans = pd(0,tot/2-x);
            
           
        printf("Teste %d\n",tc++);
        if(ans) printf("S\n");
        else printf("N\n");
        printf("\n");
    }

}

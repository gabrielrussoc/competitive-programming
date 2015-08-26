#include <cstdio>

using namespace std;

int main(){

    int n,m, v[123];
    scanf("%d %d",&n,&m);
    int ans = 1;
    for(int i = 0; i < n; i++)
        scanf("%d",&v[i]);
    
    int k=0;
    for(int i = 0; i < n; i++){
        if(k + v[i] <= m) k += v[i];
        else {
            k = 0;
            i--;
            ans++;
            
        }
    }
        
    printf("%d\n",ans);
}

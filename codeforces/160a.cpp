#include <cstdio>
#include <algorithm>

using namespace std;

int v[105];
int n;

int main(){
    scanf("%d",&n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",v+i);
        sum += v[i];
    }
    sort(v,v+n);
    int me = 0,ans=0;
    int k = n-1;
    while(me <= sum){
        me += v[k];
        sum -= v[k--];
        ans++;
    }
    printf("%d\n",ans);
}

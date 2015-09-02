#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int v[1000006];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,l;
        int mini = 0, maxi = 0;
        scanf("%d %d",&l,&n);
        for(int i = 0; i < n; i++)
            scanf("%d",v+i);
        for(int i = 0; i < n; i++){
            mini = max(mini,min(l-v[i],v[i]));
            maxi = max(maxi,max(l-v[i],v[i]));
        }
        printf("%d %d\n",mini,maxi);
    }

}

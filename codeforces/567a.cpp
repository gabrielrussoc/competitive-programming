#include <cstdio>
#include <algorithm>

using namespace std;

int v[100005];

int main(){

    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",v+i);

    printf("%d %d\n",v[2]-v[1],v[n]-v[1]);
    for(int i = 2; i < n; i++){
        printf("%d %d\n", min(v[i]-v[i-1],v[i+1]-v[i]), max(v[i]-v[1],v[n]-v[i]));
    }
    printf("%d %d\n",v[n]-v[n-1],v[n]-v[1]);

}

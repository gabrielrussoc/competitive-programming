#include <cstdio>
#include <algorithm>
using namespace std;

int v[100005];
int n;

int kadane(){
    int ans, maxi;
    ans = maxi = 0;
    for(int i = 0; i < n; i++){
        ans += v[i];
        if(ans < 0) ans = 0;
        maxi = max(ans,maxi);
    }
    return maxi;
}   

int main(){

    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",v+i);

    int sum = 0, now,w;

    now = kadane();
    for(int i = 0; i < n; i++){
        sum += v[i];
        v[i] = -v[i];
    }
    w = sum + kadane();
    printf("%d\n",max(w,now));
        

}

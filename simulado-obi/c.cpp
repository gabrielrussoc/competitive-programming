#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int freqx[100005], freqy[100005];
pii point[100005];

int main(){

    for(int i = 0; i < 100005; i++)
        freqx[i] = freqy[i] = 0;
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i = 0; i < n; i++){
        scanf("%d %d",&x,&y);
        freqx[x]++;
        freqy[y]++;
        point[i].ff = x;
        point[i].ss = y;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += (freqx[point[i].ff]-1) * (freqy[point[i].ss]-1);

    printf("%lld\n",ans);
}

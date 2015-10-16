#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[1003][2];
ll dist[1003][1003];


ll quad (ll a) { return a*a; }

int main() {
    int n;
    while(scanf("%d",&n) && n != 0){
        for(int i = 0; i < n; i++)
            scanf("%d %d",&v[i][0],&v[i][1]);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = quad(v[i][0]-v[j][0]) + quad(v[i][1]-v[j][1]);

        ll ans = 0;
        for(int i = 0; i < n; i++){
            sort(dist[i],dist[i]+n);
            int j = 0;
            for(int k = 0; k < n; k++)
                if(dist[i][j] != dist[i][k]){
                    ans += (k-j)*(k-j-1)/2;
                    j = k;
                }
            ans += (n-j)*(n-j-1)/2;
        }
        printf("%lld\n",ans);
    }
}

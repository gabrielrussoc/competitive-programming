#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
using namespace std;
typedef long long ll;

int v[100005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",v+i);

    int maxi = 0;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(v[i] >= v[i-1]) ans++;
        else{
            maxi = max(maxi,ans);
            ans = 0;
        }
    }
    maxi = max(maxi,ans);
    printf("%d\n",maxi+1);
}

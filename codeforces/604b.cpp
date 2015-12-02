#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define ff first
#define ss second
using namespace std;
typedef long long ll;

//////////////0123456789
const int N = 100005;
const int modn = 1000000007;

int s[N];

int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    int maxi = 0;
    for(int i = 0; i < n; i++)
        scanf("%d",s+i);
    int db = n-k;
    int ans = 0;
    for(int i = 0; i < db; i++)
        ans = max(ans, s[i] + s[2*db-i-1]);
    ans = max(ans,s[n-1]);
    printf("%d\n",ans);
    
}

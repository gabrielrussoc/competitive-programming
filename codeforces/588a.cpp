#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);
    int cheap = 105;
    int ans = 0;
    int a,p;
    for(int i = 0; i < n; i++){
        scanf("%d %d",&a,&p);
        cheap = min(cheap,p);
        ans += cheap*a;
    }
    printf("%d\n",ans);
}

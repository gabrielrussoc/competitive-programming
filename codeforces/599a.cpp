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

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int ans = INT_MAX;
    ans = min(ans,a+a+b+b);
    ans = min(ans,a+c+b);
    ans = min(ans,b+b+c+c);
    ans = min(ans,a+a+c+c);
    printf("%d\n",ans);
}

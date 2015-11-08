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

int n, k;
int a[N], b[N];

int f(int a, int b){
    int ans = 1;
    while (b){
        ans *= a;
        b--;
    }
    return ans;
}

int main(){
    scanf ("%d %d",&n,&k);
    for(int i = 0; i < n/k; i++) scanf("%d",&a[i]);
    for(int i = 0; i < n/k; i++) scanf("%d",&b[i]);

    ll ans = 1;
    for(int i = 0; i < n/k; i++){
        ll tmp = ((f(10,k) - 1)/a[i] +1) % modn;
        ll pri = b[i]*f(10,k-1)%a[i];
        if(!pri) pri = a[i];
        pri = b[i]*f(10,k-1) + a[i]-pri;
        if (pri <= ((b[i]+1)*f(10,k-1) -1)){
            ll ult = ((b[i]+1)*f(10,k-1) - 1)%a[i];
            ult = ((b[i]+1)*f(10,k-1)-1) - ult;
            tmp -= (ult-pri)/a[i] +1;
        }     
        ans *= tmp;
        ans %= modn;
    }
    cout << ans << endl;
}

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
const int N = 200005;
const int modn = 1000000007;

char a[N], b[N];
ll acc[N];

int main(){
    scanf("%s",a);
    scanf("%s",b);
    int la = strlen(a);
    int lb = strlen(b);
    ll ans = 0;
    acc[0] = 0;
    for(int i = 0; i < lb; i++) acc[i+1] = acc[i] + ll(b[i]-'0');
    for(int i = 0; i < la; i++){
        if(a[i] == '0')
            ans += acc[lb-la+i+1] - acc[i];
        else 
            ans += lb-la+1 - acc[lb-la+i+1] + acc[i];
    }
    cout << ans << endl;
}

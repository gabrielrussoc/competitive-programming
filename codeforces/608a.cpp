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

int v[N];

int main(){
    int n, s;
    scanf("%d %d",&n,&s);
    for(int i = 0; i < n; i++){
        int f, t;
        scanf("%d %d",&f,&t);
        v[f] = max(v[f],t);
    }
    int ans = v[s];
    for(int i = s-1; i >= 0; i--){
        ans++;
        if(v[i] > ans) ans += v[i]-ans;
    }
    printf("%d\n",ans);
}

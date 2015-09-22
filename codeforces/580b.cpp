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

pll v[100005];
ll acc[100005];

int main(){
    ll n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> v[i].ff >> v[i].ss;
    sort(v,v+n);
    acc[0] = 0;
    for(int i = 1; i <= n; i++){
        acc[i] = acc[i-1] + v[i-1].ss;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int lo = i, hi = n-1;
        while(lo != hi){
            int mid = (lo + hi+1)/2;
            if(v[mid].ff - v[i].ff >= d) hi = mid-1;
            else lo = mid;
        }
        ans = max(ans,acc[lo+1]-acc[i]);
    }
    cout << ans << endl;
}

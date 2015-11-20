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

pii f[N];
int a[N];
vector<int> v;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%d",&f[i].ff);
        f[i].ss = i;
    }
    sort(f,f+n);
    for(int i = 0; i < n; i++) v.pb(f[i].ff);
    int b;
    pair<vector<int>::iterator,vector<int>::iterator> it;
    int am = 0;
    for(int i = 0; i < m; i++){
        scanf("%d",&b);
        it = equal_range(v.begin(),v.end(),b);
        if(it.ss - it.ff == 0){
            printf("Impossible\n");
            return 0;
        }
        if(it.ss - it.ff > 1) am = 1;
        else a[i] = f[it.ff-v.begin()].ss + 1;
    }
    if(am) printf("Ambiguity\n");
    else {
        printf("Possible\n");
        for(int i = 0; i < m; i++) printf("%d ",a[i]);
        printf("\n");
    }


}

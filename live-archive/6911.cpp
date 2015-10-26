#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
const int N = 100006;
int n, a[N];
pii v[N];
set<int> s;
set<int>::iterator it;

bool comp (pii a, pii b){
    return a.ss < b.ss;
}
int main(){
    int t, tc=1;
    scanf("%d",&t);
    while(tc <= t){
        s.clear();
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d",&a[i],&v[i].ff,&v[i].ss);
            s.insert(a[i]);
        }
        int res = s.size();
        for(int i = 0; i < n; i++){
            it = s.lower_bound(v[i].ff);
            if(it != s.end() && (*it) == a[i]) ++it;
            if(it != s.end() && (*it) <= v[i].ss){
                swap(v[i],v[n-1]);
                swap(a[i],a[n-1]);
                i--, n--;
            }
        }
        sort(v,v+n,comp);
        int l = v[0].ss;
        for(int i = 1; i < n; i++){
            if(v[i].ff > l){
                res++;
                l = v[i].ss;
            }
        }
        if(n) res++;
        printf("Case #%d: %d\n",tc++,res);
    }
}

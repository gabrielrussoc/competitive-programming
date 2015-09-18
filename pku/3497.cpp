#include <vector>
#include <climits>
#include <map>
#include <algorithm>
#include <string>
#include <cstdio>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int n,b, ty;
map<string,int> m;
vector<pii> v[1003];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        m.clear();
        scanf("%d %d",&n,&b);
        for(int i = 0; i < n; i++) v[i].clear();
        string s;
        char tmp[25], foo[25];
        int pp,qq, maxq = 0;
        int k = 0;
        for(int i = 0; i < n; i++){
            scanf(" %s %s %d %d",tmp,foo,&pp,&qq);
            s = tmp;
            if(m.find(s) == m.end()) m[s] = k++;
            v[m[s]].pb(mp(pp,qq));
            maxq = max(maxq,qq);
        }
        ty = m.size();
        int lo = 0, hi = maxq;
        while(lo != hi){
            int mid = (lo+hi+1)/2;
            int tot = 0,i;
            for(i = 0; i < ty; i++){
                int mini = INT_MAX;
                for(int j = 0; j < v[i].size(); j++){
                    if(v[i][j].ss >= mid)
                        mini = min(mini,v[i][j].ff);
                }
                if(mini != INT_MAX) tot += mini;
                else break;   
            }
            if(tot <= b && i == ty) lo = mid;
            else hi = mid-1;
        }
        printf("%d\n",lo);
    }
}

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 1000004;
const int modn = 1000000007;

int z,n,m, t[N], v[N], ans[N], k;

set<int> chuva[N];
struct comp {
    bool operator () (const int &a, const int &b) const {
        int fa, fb;
        if(chuva[a].empty()) return 0;
        if(chuva[b].empty()) return 1;
        fa = *(chuva[a].begin());
        fb = *(chuva[b].begin());
        return fa < fb;
    }
};
set<int,comp> cheio;



void bebe(){
    if(cheio.empty()) ans[k++] = 0;
    else {
        int at = *(cheio.begin());
        v[at] = 0;
        ans[k++] = at+1;
        cheio.erase(cheio.begin());
    }
}

int main() {
    scanf("%d",&z);
    while(z--){
        cheio.clear();
        int zer = 0;
        k = 0;
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++) {
            v[i] = 1; 
            chuva[i].clear();
        }
        for(int i = 0; i < m; i++){
            scanf("%d",t+i);
            if(!t[i]) zer++;
            else chuva[t[i]-1].insert(i);
        }
        for(int i = 0; i < n; i++) cheio.insert(i);
        bool xab = 0;
        for(int i = 0; i < m && !xab; i++){
            if(!t[i]) bebe();
            else {
                if(v[t[i]-1]) xab = 1;
                v[t[i]-1] = 1;
                chuva[t[i]-1].erase(i);
                if(!chuva[t[i]-1].empty())
                    cheio.insert(t[i]-1);
            }
        }
        if(xab) puts("NO");
        else {
            puts("YES");
            for(int i = 0; i < k; i++) printf("%d%c",ans[i], i == k-1 ? '\n' : ' ');
        }
    }
}


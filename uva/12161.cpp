#include <bits/stdc++.h>
#define dmg first
#define len second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 31234;

struct edge {
    int v, d, l;
};
vector<edge> adj[N];
int ans;
int n, m;

struct comp {
    bool operator () (pii a, pii b) const {
        if(a.dmg == b.dmg) return a.len > b.len;
        return a.dmg < b.dmg;
    }
};

struct paths {
    int d, l; //to add later
    set<pii, comp> s;
    void reset() {
        d = l = 0;
        s.clear();
        s.insert(pii(0,0));
    }
    void get_best(pii a){
        int k = m - a.dmg - d;
        auto it = s.upper_bound(pii(k, -1));
        if(it != s.begin()) ans = max(ans, prev(it)->len + a.len + l);
    }
    void add(pii a){
        a.dmg -= d; a.len -= l;
        if(s.count(a)) return;
        auto it = s.insert(a).first;
        if(it != s.begin() && prev(it)->len >= a.len){s.erase(it); return;}
        while(next(it) != s.end() && a.len >= next(it)->len) s.erase(next(it));
    }
    void join (paths &o) {
        if(s.size() < o.s.size()){
            s.swap(o.s);
            swap(d,o.d);
            swap(l,o.l);
        } //this has the bigger set
        for(pii a : o.s) {
            a.dmg += o.d; a.len += o.l;
            get_best(a);
        }
        for(pii a : o.s) {
            a.dmg += o.d; a.len += o.l;
            add(a);
        }
    }
} bp[N];


void dfs(int u, int p) {
    bp[u].reset();
    for(edge e : adj[u]) {
        int v = e.v;
        if(v == p) continue;
        dfs(v, u);
        bp[v].d += e.d; 
        bp[v].l += e.l; 
        bp[u].join(bp[v]);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n-1; i++){
            int a,b,d,l;
            scanf("%d %d %d %d",&a,&b,&d,&l); a--; b--;
            adj[a].pb(edge{b,d,l});
            adj[b].pb(edge{a,d,l});
        }
        ans = 0;
        dfs(0,-1);
        printf("Case %d: %d\n",tc, ans);
        for(int i = 0; i < n; i++) adj[i].clear();
    }
    
}
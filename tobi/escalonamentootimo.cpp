#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#define pb push_back
#define mp make_pair
#define N 50004
#define m0(x) memset(x,0,sizeof x);

using namespace std;

vector<int> adj[N];
int g[N];
vector<int> ans;
bool ok;
int n,m;

void toposort(){
    set<int> s;
    set<int>::iterator it;
    for(int i = 0; i < n; i++) if(!g[i]) s.insert(i);
    while(s.size()){
        it = s.begin();
        s.erase(it);
        int p = *it;
        ans.pb(p);
        int k = adj[p].size();
        for(int i = 0; i < k; i++){
            g[adj[p][i]]--;
            if(!g[adj[p][i]]) s.insert(adj[p][i]);
        }
    }
    for(int i = 0; i < n; i++){
        if(g[i]){ 
            ok = false;
            return;
        }
    }
    ok = true;
}

int main(){
    m0(g);
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].pb(b);
        g[b]++;
    }
    toposort();
    if(ok){
        for(int i = 0; i < ans.size(); i++)
            printf("%d\n",ans[i]);
    }
    else
        printf("*\n");

}

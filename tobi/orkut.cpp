#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back

using namespace std;

int n,mm;
int g[35];
map<string,int> m;
vector<int> adj[35];
vector<int> ans;
string ppl[35];
bool ok;

void toposort(){
    set<int> s;
    set<int>::iterator it;
    for(int i = 0; i < n; i++) if(!g[i]) s.insert(i);
    while(s.size()){
        it = s.begin();
        int p = *it;
        s.erase(it);
        ans.pb(p);
        int k = adj[p].size();
        for(int i = 0; i < k; i++){
            g[adj[p][i]]--;
            if(!g[adj[p][i]]) s.insert(adj[p][i]);
        }
    }
    for(int i = 0; i < n; i++)
        if(g[i]){
            ok = false;
            return;
        }

    ok = true;
}

int tc = 1;

int main(){
    while(scanf("%d",&n) && n != 0){
        m.clear();
        map<string,int>::iterator it;
        ans.clear();
        string s,ss;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            g[i] = 0;
            cin >> s;
            m[s] = i;
        }
        for(int i = 0; i < n; i++){
            cin >> s;
            scanf("%d",&mm);
            for(int j = 0; j < mm; j++){
                cin >> ss;
                adj[m[s]].pb(m[ss]);
                g[m[ss]]++;
            }
        }
        toposort();
        printf("Teste %d\n",tc++);
        if(ok){
            for(it = m.begin(); it != m.end(); it++)
                ppl[it->second] = it->first;
            for(int i = n-1; i >= 0; i--)
                printf("%s ",ppl[ans[i]].c_str());
        }
        else
            printf("impossivel\n");
        printf("\n");
    }
}

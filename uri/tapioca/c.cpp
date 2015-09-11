#include <cstdio>
#include <vector>
#include <climits>
#include <set>
#define pb push_back
#include <map>
#include <queue>
#include <string>

using namespace std;

map<string,int> m;
vector<int> adj[1004];
int d[100000];

void clean(int k){
    for(int i = 0; i <= k; i++)
        d[i] = INT_MAX;
}

void bfs(int ini){
    queue<int> q;
    q.push(ini);
    d[ini] = 0;
    while(q.size()){
        int at, nxt;
        at = q.front();
        q.pop();
        int k = adj[at].size();
        for(int i = 0; i < k; i++){
            nxt = adj[at][i];
            if(d[nxt] > d[at]+1){
                d[nxt] = d[at]+1;
                q.push(nxt);
            }
        }
    }
}

int main(){
    int n, G;
    scanf("%d %d",&n,&G);
    m["Rerisson"] = 0;
    char s1[25], s2[25];
    string a,b;
    int k = 1;
    for(int i = 0; i < n; i++){
        scanf("%s %s",s1,s2);
        a = s1;
        b = s2;
        if(m.find(a) == m.end()) m[a] = k++;
        if(m.find(b) == m.end()) m[b] = k++;
        adj[m[a]].pb(m[b]);
        adj[m[b]].pb(m[a]);
    }
    clean(k);
    bfs(0);
    set<string> ans;
    set<string>::iterator it2;
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
        if(d[it->second] <= G && d[it->second] > 0) ans.insert(it->first);
    
    printf("%d\n",ans.size());
    for(it2 = ans.begin(); it2 != ans.end(); it2++)
        printf("%s\n",(*it2).c_str());

}

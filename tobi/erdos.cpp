#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
#define pb push_back

using namespace std;

char nome[15][60];
char line[230];
string out[100];
map<string,int> m;
map<string,int>::iterator it;
int r, p;
vector<int> adj[100];
int d[100];

bool comp(string a, string b) {
    const char *s1, *s2;
    s1 = a.c_str();
    s2 = b.c_str();
    if(strcmp(s1+3,s2+3) < 0) return true;
    if(strcmp(s1+3,s2+3) == 0) return a[0] < b[0];
    return false;

}

void solve(){
    int k = strlen(line);
    line[k-1] = ',';
    int j = 0, erd;
    p = 0;
    bool ok = false;
    for(int i = 0; i < k; i++) {
        if(line[i] == ','){
            line[i] = '\0';
            strcpy(nome[p],line+j);
            if(m.find(nome[p]) == m.end()){
                m[nome[p]] = r++;
            }
            j = i+2;
            p++;
        }
    }
    for(int i = 0; i < p; i++) {
        for(int g = i+1; g < p; g++){
           adj[m[nome[i]]].pb(m[nome[g]]);
           adj[m[nome[g]]].pb(m[nome[i]]);
        }
    }
}

void inf(){
    for(int i = 0; i < 100; i++)
        d[i] = INT_MAX;
}

void bfs(int ini){
    queue<int> q;
    q.push(ini);
    d[ini] = 0;
    while(q.size()){
        int a,b,k;
        a = q.front();
        q.pop();
        k = adj[a].size();
        for(int i = 0; i < k; i++){
            b = adj[a][i];
            if(d[b] > d[a]+1){
                d[b] = d[a]+1;
                q.push(b);
            }
        }
    }
}

void limpatudojesus(){
    for(int i = 0; i < 100; i++)
        adj[i].clear();
}

int main(){
    int n, tc = 1;
    while(scanf("%d",&n) && n != 0){
        printf("Teste %d\n",tc++);
        r = 1;
        limpatudojesus();
        m["P. Erdos"] = 0;
        for(int i = 0; i < n; i++){
            scanf(" %[^\n]",line);
            solve();
        }
        inf();
        bfs(0);
        int t = 0;
        for(it = m.begin(); it != m.end(); it++){
            if(it->first != "P. Erdos")
                out[t++] = it->first;
        }
        sort(out,out+t,comp);
        for(int i = 0; i < t; i++){
            if(d[m[out[i]]] == INT_MAX)
                printf("%s: infinito\n",out[i].c_str());
            else
                printf("%s: %d\n", out[i].c_str(),d[m[out[i]]]);
        }
        m.clear();
        printf("\n");
    }
    
}

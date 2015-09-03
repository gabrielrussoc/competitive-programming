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
map<string,int> m;
map<string,int>::iterator it;
int r, p;
vector<int> adj[100];
int d[100];

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
        for(int i = 1; i < r; i++){
            if(d[i] == INT_MAX)
                printf("%s: infinito\n",nome[i]);
            else
                printf("%s: %d\n", d[i]);
        }
        m.clear();
        printf("\n");
    }
    
}

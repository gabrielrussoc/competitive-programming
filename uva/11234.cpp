#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;

char v[10004];
int ans[10004];
stack<int> s;
vector<int> adj[10004];

void solve(int a){
    queue<int> q;
    q.push(a);
    int k = 0;
    while(q.size()){
        int x = q.front();
        q.pop();
        ans[k++] = x;
        for(int i = 0; i < adj[x].size(); i++)
            q.push(adj[x][i]);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf(" %s",v);
        int k = strlen(v);
        for(int i = 0; i < k; i++){
            adj[i].clear();
            if(isupper(v[i])){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                adj[i].pb(y);
                adj[i].pb(x);
            }        
            s.push(i);
        }
        s.pop();
        solve(k-1);
        for(int i = k-1; i >= 0; i--)
            printf("%c",v[ans[i]]);
        printf("\n");
    }
}

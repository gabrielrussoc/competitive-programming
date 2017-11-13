#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const int A = 27;
bool adj[A][A], has[A];
int indeg[A], outdeg[A];
int n;

void fail() {
    puts("NO");
    exit(0);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(char c : s) has[c-'a'] = true;
        for(int i = 1; i < s.size(); i++) {
            int u = s[i-1]-'a';
            int v = s[i]-'a';
            if(!adj[u][v]) {
                indeg[v]++;
                outdeg[u]++;
                if(indeg[v] > 1 || outdeg[u] > 1) fail();
            }
            adj[u][v] = true;
        }
    }
    vector<int> l;
    for(int u = 0; u < A; u++) if(has[u] && !indeg[u]) l.pb(u);

    vector<char> ans;
    for(int u : l) {
        int v = u;
        ans.pb(v + 'a');
        while(outdeg[v]) {
            for(int w = 0; w < A; w++) if(adj[v][w]) { v = w; break; }
            ans.pb(v + 'a');
        }
    }
    int cnt = 0;
    for(int u = 0; u < A; u++) if(has[u]) cnt++;
    if(ans.size() != cnt) fail();
    for(char c : ans) putchar(c);
    putchar('\n');
}

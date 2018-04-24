#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1000006;

vector<string> text;
set<int> nxt[N], prv[N];
map<string, int> id;
int idc = 1;
bool dot[N], vis[N][2], after[N];

string strip(const string &s) {
    int cut = 0;
    if(!isalpha(s.back())) cut++;
    return s.substr(0, s.length() - cut);
}

void dfs(int u, bool f) {
    if(vis[u][f]) return;
    vis[u][f] = 1;
    if(f) {
        for(int v : nxt[u])
            dfs(v, !f);
    } else {
        for(int v : prv[u])
            dfs(v, !f);
    }
}

int main() {
    string s;
    
    for(int i = 0; cin >> s; i++) {
        string clean = strip(s);
        if(!id[clean]) id[clean] = idc++;
        int u = id[clean];
        if(s.back() == ',') after[u] = true;
        text.pb(clean);
        if(s.back() == '.') dot[i] = true;
    }

    int n = text.size();
    if(n > 1) {
        if(!dot[0]) nxt[id[text[0]]].insert(id[text[1]]);
        if(!dot[n-2]) prv[id[text[n-1]]].insert(id[text[n-2]]);
    }
    for(int i = 1; i < n-1; i++) {
        if(!dot[i]) nxt[id[text[i]]].insert(id[text[i+1]]);
        if(!dot[i-1]) prv[id[text[i]]].insert(id[text[i-1]]);
    }

    for(int i = 1; i < idc; i++) {
        if(after[i]) dfs(i, 1);
    }
    bool beg = true;
    for(int i = 0; i < n; i++) {
        string &s = text[i];
        int u = id[s];
        if(!beg && vis[u][0]) cout << ", ";
        else if(i > 0) cout << " ";
        cout << text[i];
        if(dot[i]) {
            cout << '.';
            beg = true;
        } else beg = false;
    }
    cout << endl;
}


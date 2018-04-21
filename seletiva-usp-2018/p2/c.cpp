#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1000006;

map<char, int> trie[N];
int root = 1, ts = 2;
int n, m;
int freq[N], dep[N];

set<int> adj[N];
int dist[N];

void add(const string &s) {
    int node = root;
    stack<int> history;
    int d = 1;
    for(char c : s) {
        int &nx = trie[node][c];
        if(!nx) nx = ts++;
        adj[node].insert(nx);
        adj[nx].insert(node);
        node = nx;
        history.push(nx);
        dep[nx] = d++;
    }
    while(!history.empty()) {
        int cur = history.top();
        history.pop();
        if(!freq[cur]) {
            freq[cur] = node;
            adj[cur].insert(node);
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(!dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int query(const string &s) {
    int node = root;
    int sz = s.length();
    int ans = sz;
    for(char c : s) {
        int nx = trie[node][c];
        ans = min(ans, dist[nx] + sz - dep[nx]);
        node = nx;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }
    bfs();
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << query(s) << endl;
    }
}


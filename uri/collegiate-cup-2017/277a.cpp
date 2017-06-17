//autor: germanohn
#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

int n;
int p[N];
vector<int> adj[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        a--;

        if (a == i) continue;

        adj[a].pb(i);
    }

    int s, c;
    scanf(" %d %d", &s, &c);
    while (s--) {
        for (int i = 0; i < n; i++) {
            p[i] = 0;
        }

        for (int i = 0; i < c; i++) {
            int a;
            scanf(" %d", &a);
            a--;
            p[a] = true;
        }

        bool ok = true;
        for (int i = 0; ok && i < n; i++) {
            if (!p[i]) {
                for (int j = 0; j < adj[i].size(); j++) {
                    int v = adj[i][j];
                    if (p[v]) {
                        ok = false;
                    }
                }
            }
        }

        if (ok) printf("yes\n");
        else printf("no\n");
    }
}


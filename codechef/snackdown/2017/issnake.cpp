#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 503;
int t, n, turn;
char g[2][N];
int vis[2][N];

bool single(int i) {
    return g[0][i] != g[1][i];
}

int line(int i) {
    return g[0][i] == '#';
}

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};


bool can(int i, int j) {
    return i >= 0 && i < 2 && j >= 0 && j < n && vis[i][j] != turn && g[i][j] == '#';
}

void dfs(int ui, int uj) {
    vis[ui][uj] = turn;
    for(int k = 0; k < 4; k++) {
        int vi = ui + di[k];
        int vj = uj + dj[k];
        if(can(vi, vj)) {
            dfs(vi, vj);
        }
    }
}

bool disc() {
    int si, sj;
    si = sj = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == '#') {
                si = i;
                sj = j;
            }
        }
    }
    turn++;
    dfs(si, sj);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++)
            if(g[i][j] == '#' && vis[i][j] != turn) return true;
    }
    return false;
}

bool imp(int sz, int l, int r) {
    if(sz == -1) return false;
    if(l == r && sz % 2 == 1) return true;
    if(l != r && sz % 2 == 0) return true;
    return false;
}

bool solve() {
    int i = 0;
    if(disc()) return false;
    for(int j = 0; j < n; j++){
        if(g[0][j] == '#' || g[1][j] == '#') {
            i = j;
            break;
        }
    }
    int k = n;
    for(int j = n - 1; j >= 0; j--) {
        if(g[0][j] == '#' || g[1][j] == '#') {
            k = j + 1;
            break;
        }
    }
    int lsz = -1;
    int l = -1;
    while(i < k && !single(i)) i++;
    while(i < k) {
        int r = line(i);
        while(i < k && single(i) && line(i) == r) i++;
        if(imp(lsz, l, r)) return false;
        int sz = 0;
        while(i < k && !single(i)) {
            i++;
            sz++;
        }
        l = r;
        lsz = sz;
    }
    return true;
}

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                scanf(" %c", &g[i][j]);
            }
        }
        if(solve()) puts("yes");
        else puts("no");
    }
    
}


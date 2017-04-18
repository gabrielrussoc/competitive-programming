#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;

int n, g;
int a[N][5], vis[N][2], turn;

void dfs(int u, int f) {
    int d = (a[u][0] == f || a[u][1] == f) ? 0 : 1;
    if(f == -1) d = 0;
    if(f == -2) d = 1;
    //printf("%d (%d)\n", u+1, d);
    if(vis[u][d] == turn)  {
        //puts("fim");
        return;
    }
    vis[u][d] = turn;
    if(f == -1) {
        dfs(a[u][1], u);
    } else if (f == -2) {
        dfs(a[u][3], u);
    } else {
        if(f == a[u][0]) dfs(a[u][1], u);
        else if(f == a[u][1]) dfs(a[u][0], u);
        else if(f == a[u][2]) dfs(a[u][3], u);
        else dfs(a[u][2], u);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        turn++;
        scanf("%d %d", &n, &g); g--;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &a[i][0], &a[i][2], &a[i][1], &a[i][3]);
            //printf("%d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3]);
            a[i][0]--; a[i][1]--; a[i][2]--; a[i][3]--;
        }
        int ans = 0;
        if(vis[g][0] != turn) {
            dfs(g, -1);
        }
        if(vis[g][1] != turn) {
            dfs(g, -2);
        }
        for(int i = 0; i < n; i++) {
            if(i == g) continue;
            if(vis[i][0] != turn) { 
                dfs(i, -1);
                ans++;
            }
            if(vis[i][1] != turn) {
                dfs(i, -2);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}


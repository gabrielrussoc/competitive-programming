#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 1005;
const int inf = 11234567;

int adj[N][N];
map<pii, int> mp;
set<int> fl[N];

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, f, m, ps;
        scanf("%d %d %d",&n, &f, &m);
        ps = n;
        mp.clear();
        for(int i = 0; i < n; i++) {
            fl[i].clear();
            fl[i].insert(0);
        }
        for(int i = 0; i < 2*(n+m); i++) {
            adj[i][i] = 0;
            for(int j = i+1; j < 2*(n+m); j++)
                adj[i][j] = adj[j][i] = inf; 
        }
        adj[0][n-1] = adj[n-1][0] = 1;
        for(int i = 0; i < n; i++) {
            adj[i][i+1] = adj[i+1][i] = 1;
            mp[pii(i, 0)] = i;
        }
        adj[n-1][n] = adj[n][n-1] = inf;
        for(int i = 0; i < m; i++) {
            int bi, fi, bj, fj, w;
            scanf("%d %d %d %d %d",&bi, &fi, &bj, &fj, &w);
            bi--; bj--; fi--; fj--;
            pii a = pii(bi, fi);
            pii b = pii(bj, fj);
            if(!mp.count(a)) mp[a] = ps++;
            if(!mp.count(b)) mp[b] = ps++; 
            int u = mp[a];
            int v = mp[b];
            adj[u][v] = min(adj[u][v], w);
            adj[v][u] = min(adj[v][u], w);
            fl[bi].insert(fi);
            fl[bj].insert(fj);
        }
        for(int i = 0; i < n; i++) {
            for(set<int>::iterator it = ++fl[i].begin(); it != fl[i].end(); it++) {
                int fa = *(--it);
                int fb = *(++it);
                pii a = pii(i, fa);
                pii b = pii(i, fb);
                if(!mp.count(a)) mp[a] = ps++;
                if(!mp.count(b)) mp[b] = ps++;
                int u = mp[a];
                int v = mp[b];
                adj[u][v] = min(adj[u][v], abs(fb-fa));
                adj[v][u] = min(adj[v][u], abs(fb-fa));
            }
        }
        
        for(int k = 0; k < ps; k++)
            for(int i = 0; i < ps; i++)
                for(int j = 0; j < ps; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int q;
        scanf("%d",&q);
        while(q--) {
            int bi, fi, bj, fj;
            scanf("%d %d %d %d", &bi, &fi, &bj, &fj);
            bi--; fi--; bj--; fj--;
            int pa, pb, na, nb;
            set<int>::iterator it;

            it = fl[bi].upper_bound(fi);
            if(it != fl[bi].end()) na = *it;
            else na = -1;
            if(it != fl[bi].begin()) pa = *(--it);
            else pa = -1;
            
            it = fl[bj].upper_bound(fj);
            if(it != fl[bj].end()) nb = *it;
            else nb = -1;
            if(it != fl[bj].begin()) pb = *(--it);
            else pb = -1;

            //printf("query (%d, %d) - (%d, %d)\n", bi+1, fi+1, bj+1, fj+1);
            //printf("vizinhos de a: %d %d\n", na+1, pa+1);
            //printf("vizinhos de b: %d %d\n", nb+1, pb+1);
                
            int ans = INT_MAX;
            if(na != -1) {
                if(nb != -1) {
                    int d = abs(fi-na) + abs(fj-nb);
                    int u = mp[pii(bi, na)];
                    int v = mp[pii(bj, nb)];
                    ans = min(ans, d + adj[u][v]);
                    //printf("Com %d %d deu %d (%d)\n", na+1, nb+1, d + adj[u][v], d);
                } 
                if(pb != -1) {
                    int d = abs(fi-na) + abs(fj-pb);
                    int u = mp[pii(bi, na)];
                    int v = mp[pii(bj, pb)];
                    ans = min(ans, d + adj[u][v]);
                    //printf("Com %d %d deu %d (%d)\n", na+1, pb+1, d + adj[u][v], d);
                }
            } 
            if(pa != -1) {
                if(nb != -1) {
                    int d = abs(fi-pa) + abs(fj-nb);
                    int u = mp[pii(bi, pa)];
                    int v = mp[pii(bj, nb)];
                    ans = min(ans, d + adj[u][v]);
                    //printf("Com %d %d deu %d (%d)\n", pa+1, nb+1, d + adj[u][v], d);
                } 
                if(pb != -1) {
                    int d = abs(fi-pa) + abs(fj-pb);
                    int u = mp[pii(bi, pa)];
                    int v = mp[pii(bj, pb)];
                    ans = min(ans, d + adj[u][v]);
                    //printf("Com %d %d deu %d (%d)\n", pa+1, pb+1, d + adj[u][v], d);
                }
            }
            if(bi == bj) ans = min(ans, abs(fi-fj));
            printf("%d\n", ans);
        }
    }
}
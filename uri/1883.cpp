#include <cstdio>
#include <queue>
#include <climits>
#include <vector>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

char g[1005][1005];
int d[1005][1005];
int n, m;
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};
vector<pii> fire;
pii in, out;

void bfs(){
    queue<pii> q;
    q.push(out);
    d[out.ff][out.ss] = 0;
    pii at, nxt;
    while(q.size()){
        at = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            nxt.ff = at.ff+vx[i];
            nxt.ss = at.ss+vy[i];
            if (g[nxt.ff][nxt.ss] != '#'){
                if(d[nxt.ff][nxt.ss] > d[at.ff][at.ss] + 1){
                    d[nxt.ff][nxt.ss] = d[at.ff][at.ss]+1;
                    q.push(nxt);
                }
            }        
        }
    }
}

void clean(){
    fire.clear();
    for(int i = 0; i < n+2; i++)
        for(int j = 0; j < m+2; j++)
            g[i][j] = '#', d[i][j] = INT_MAX;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        clean();
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j] == 'S') in = mp(i,j);
                else if(g[i][j] == 'E') out = mp(i,j);
                else if(g[i][j] == 'F') fire.pb(mp(i,j));
            }
        bfs(); 
        int exit = d[in.ff][in.ss];
        bool ans = true;
        int k = fire.size();
        for(int i = 0; i < k; i++)
            if(d[fire[i].ff][fire[i].ss] <= exit){ 
                ans = false; 
                break;
            }      
        if(ans)
            printf("Y\n");
        else
            printf("N\n");
    }
}

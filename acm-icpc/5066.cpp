#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};

char predio[105][105][15];
int d[105][105][15];
int p[104], W[104];
int t,l,h,w,n,s;

typedef struct tripla {
    int f, s, t;
} tii;
typedef long long ll;

ll memo[105][10004];

void clean(){
    for(int k = 0; k < l; k++) 
        for(int i = 0; i < h+2; i++)
            for(int j = 0; j < w+2; j++)
                predio[i][j][k] = 'X', d[i][j][k] = INT_MAX;
}

tii mt(int i, int j, int k){
    tii x;
    x.f = i;
    x.s = j;
    x.t = k;
    return x;
}

ll pd (int i, int v){
    if(v < 0) return INT_MIN;
    if(i == n) return 0;
    ll &me = memo[i][v];
    if(me != -1) return me;
    me = max(W[i] + pd(i+1,v-p[i]),pd(i+1,v));
    return me;
}

void bfs(tii ini){
    queue<tii> q;
    d[ini.f][ini.s][ini.t] = 0;
    q.push(ini);
    while(q.size()){
        tii x = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            tii nxt = mt(x.f+vx[i],x.s+vy[i],x.t);
            if(predio[nxt.f][nxt.s][nxt.t] != 'X'){
                if(d[nxt.f][nxt.s][nxt.t] > d[x.f][x.s][x.t] + 1){
                    d[nxt.f][nxt.s][nxt.t] = d[x.f][x.s][x.t] + 1;
                    q.push(nxt);
                }
            }
            if(predio[x.f][x.s][x.t] == 'U'){
                if(d[x.f][x.s][x.t+1] > d[x.f][x.s][x.t] + 1){
                    d[x.f][x.s][x.t+1] = d[x.f][x.s][x.t] + 1;
                    q.push(mt(x.f,x.s,x.t+1));
                } 
            }    
            if(predio[x.f][x.s][x.t] == 'D'){
                if(d[x.f][x.s][x.t-1] > d[x.f][x.s][x.t] + 1){
                    d[x.f][x.s][x.t-1] = d[x.f][x.s][x.t] + 1;
                    q.push(mt(x.f,x.s,x.t-1));
                } 
            }    
        }
    }
    
}

int main(){
    
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d",&l,&h,&w,&n,&s);
        clean();
        tii ini;
        for(int k = 0; k < l; k++){
            for(int i = 1; i <= h; i++)
                for(int j = 1; j <= w; j++){
                    scanf(" %c",&predio[i][j][k]);
                    if(predio[i][j][k] == 'S')
                        ini = mt(i,j,k);
                }
        }
        bfs(ini);
        int a,b,c,g;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d",&a,&b,&c,&g);
            a--;
            if(d[b][c][a] != INT_MAX){
                p[i] = 3*d[b][c][a];
            }
            else
                p[i] = INT_MAX;
            W[i] = g;
        }
        memset(memo,-1,sizeof memo);
        ll ans = pd(0,s);
        printf("%lld\n",ans);
    }    


}

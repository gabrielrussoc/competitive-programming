#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef struct triple {
    int ff,ss,tt;
} tii;
typedef pair<int,int> pii;
const int N = 105;
int r,c, d[N][N][40];
pii st;
vector<pii> end;
char g[N][N];
int vx[] = {0,0,1,-1};
int vy[] = {1,-1,0,0};

triple mt(int a, int b, int c){
    triple x;
    x.ff = a, x.ss = b, x.tt = c;
    return x;
}

int bla(char c){
    c = tolower(c);
    if(c == 'b') return 0;
    if(c == 'y') return 1;
    if(c == 'r') return 2;
    if(c == 'g') return 3;
}

int go(int i, int j, int bit){
    if(g[i][j] == '#') return 0;
    if(isupper(g[i][j]) && g[i][j] != 'X') return (1<<(bla(g[i][j]))) & bit;
    return 1;
}

int let(int i, int j){
    if(islower(g[i][j])) return 1<<(bla(g[i][j]));
    return 0;
}

void bfs(){
    queue<tii> q;
    q.push(mt(st.first,st.second,0));
    d[st.first][st.second][0] = 0;
    while(q.size()){
        tii at = q.front();
        q.pop();
        int w = d[at.ff][at.ss][at.tt];
        at.tt |= let(at.ff,at.ss);
        d[at.ff][at.ss][at.tt] = w;
        for(int k = 0; k < 4; k++){
            int nx = at.ff + vx[k];
            int ny = at.ss + vy[k];
            int dist = d[at.ff][at.ss][at.tt];
            if(d[nx][ny][at.tt] > dist + 1 && go(nx,ny,at.tt)){
                d[nx][ny][at.tt] = dist +1;
                q.push(mt(nx,ny,at.tt));
            }
        }
    }

}

int main(){
    while(scanf("%d %d",&r,&c) && r != 0){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                g[i][j] = '#';
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < 40; k++)
                    d[i][j][k] = INT_MAX;

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j] == '*') st = pii(i,j);
                if(g[i][j] == 'X') end.pb(pii(i,j));
            }

        bfs();
        int ans = INT_MAX;
        for(int j = 0; j < end.size(); j++)
            for(int i = 0; i < 40; i++)
                ans = min(ans,d[end[j].first][end[j].second][i]);

        if(ans == INT_MAX)
            printf("The poor student is trapped!\n");
        else
           printf("Escape possible in %d steps.\n",ans); 
        end.clear();
    }
}

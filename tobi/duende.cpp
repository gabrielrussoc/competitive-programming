#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
#define ff first
#define ss second
#define pii pair<int,int>
#define mp make_pair
using namespace std;

int d[13][13];
pii exits[13];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};

void bfs(pii ini){
    queue<pii> q;
    q.push(ini);
    d[ini.ff][ini.ss] = 0;

    while(q.size()){
        pii at = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pii nxt = mp(at.ff+vx[i],at.ss+vy[i]);
            if(d[nxt.ff][nxt.ss] > d[at.ff][at.ss] + 1){
                d[nxt.ff][nxt.ss] = d[at.ff][at.ss] + 1;
                q.push(nxt);
            }
        }
    }
}

int main(){

    for(int i = 0; i < 13; i++)
        for(int j = 0; j < 13; j++)
            d[i][j] = -1;

    int n,m;
    cin >> n >> m;

    pii ini;
    int k = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int a;
            cin >> a;
            if(a == 0){
                d[i][j] = INT_MAX;
                exits[k++] = mp(i,j);
            }
            else if(a == 2) d[i][j] = -1;
            else if(a == 3) ini = mp(i,j);
            else d[i][j] = INT_MAX;
        }

    bfs(ini);
    int ans = INT_MAX;
    for(int i = 0; i < k; i++)
        ans = min(ans,d[exits[i].ff][exits[i].ss]);

    cout << ans << endl;


}

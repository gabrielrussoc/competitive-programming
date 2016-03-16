#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int dx[5] = {0, 0, 1, -1, 0};
const int dy[5] = {1, -1, 0, 0, 0};
int r, c;
char g[65][65];
int p, q, v[205];
pii pat[205][19];
int d[65][65][3600];

int mdc(int a, int b){
    if(!b) return a;
    return mdc(b,a%b);
}

struct tii {
    int i,j,t;
    tii () {};
    tii (int a, int b, int c) : i(a), j(b), t(c) {};
};

queue<tii> qu;

bool isval(int i, int j, int t) {
    if(i >= r || i < 0) return false;
    if(j >= c || j < 0) return false;
    if(g[i][j] == '#') return false;
    return true;
}

char fds;

int main() {
    scanf("%d %d",&r,&c);
    int stx, sty, edx, edy;
    scanf(" %c", &fds);
    scanf("%d %d",&stx,&sty);
    scanf(" %c", &fds);
    scanf(" %c", &fds);
    scanf("%d %d",&edx,&edy);
    scanf(" %c", &fds);
    stx--; sty--; edx--; edy--;
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf(" %c",&g[i][j]);

    scanf("%d",&p);
    for(int i = 0; i < p; i++) {
        scanf("%d",&q);
        v[i] = q;
        int a,b;
        for(int j = 0; j < q; j++) {
            scanf(" %c", &fds);
            scanf("%d %d",&a, &b);
            a--; b--;
            scanf(" %c", &fds);
            pat[i][j] = pii(a,b);
        }
        if(q == 1) continue;
        v[i] += q-2;
        for(int j = 0; j < q-2; j++) pat[i][q+j] = pat[i][q-j-2];
    }
    int mmc = v[0];
    for(int i = 1; i < p; i++) {
        int k = mdc(mmc,v[i]);
        mmc *= v[i]; mmc /= k;
    }
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            for(int t = 0; t < mmc; t++)
                d[i][j][t] = INT_MAX;
    
    for(int i = 0; i < mmc; i++){
        for(int j = 0; j < p; j++) {
            pii w = pat[j][i%v[j]];
            int k = 0;
            while(isval(w.first+k, w.second, i)) d[w.first+k][w.second][i] = -1, k++;
            k = 0;
            while(isval(w.first-k, w.second, i)) d[w.first-k][w.second][i] = -1, k++;
            k = 0;
            while(isval(w.first, w.second+k, i)) d[w.first][w.second+k][i] = -1, k++;
            k = 0;
            while(isval(w.first, w.second-k, i)) d[w.first][w.second-k][i] = -1, k++;
        }
    }
    for(int i = 0; i < mmc; i++)
        d[edx][edy][i] = INT_MAX;
    d[stx][sty][0] = 0;
    qu.push(tii(stx,sty,0));
    while(!qu.empty()) {
        tii at = qu.front(); qu.pop();
        for(int i = 0; i < 5; i++) {
            tii nxt = tii(at.i+dx[i], at.j+dy[i],(at.t+1)%mmc);
            if(isval(nxt.i,  nxt.j, nxt.t)) {
                if(d[nxt.i][nxt.j][nxt.t] > d[at.i][at.j][at.t] + 1) {
                    d[nxt.i][nxt.j][nxt.t] = d[at.i][at.j][at.t] + 1;
                    qu.push(nxt);
                }
            }
        }
    }

    int mini = INT_MAX;
    for (int i = 0; i < mmc; i++) {
        mini = min(d[edx][edy][i], mini);
    }

    if (mini == INT_MAX)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", mini);
}


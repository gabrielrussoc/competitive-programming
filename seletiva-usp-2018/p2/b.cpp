#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1004;
const int Q = 10004;

int n, m, q;

int uf[N*N], wf[N*N], ans[Q];
int grid[N][N];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct qry {
    int x1, y1, x2, y2;
    qry(){}
    qry(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
} query[Q];

int find(int p) {
    if(uf[p] == p) return p;
    return uf[p] = find(uf[p]);
}

bool join(int p, int q) {
    p = find(p); q = find(q);
    if(p == q) return false;
    if(wf[p] > wf[q]) swap(p, q);
    uf[p] = q;
    wf[q] += wf[p];
    return true;
}

int id(int x, int y) {
    return x*m+y;
}

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !grid[x][y];
}

int add(int x, int y) {
    set<int> white;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!valid(nx, ny)) continue;
        white.insert(find(id(nx,ny)));
    }
    int orig = white.size();
    if(!orig) return 1;
    white.clear();
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!valid(nx, ny)) continue;
        join(id(x, y), id(nx, ny));
    }
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!valid(nx, ny)) continue;
        white.insert(find(id(nx,ny)));
    }
    int neu = white.size();
    return neu - orig;
}

int paint(int x1, int y1, int x2, int y2, int v, bool apply = false) {
    int ret = 0;
    if(x1 == x2) {
        for(int y = y1; y <= y2; y++) {
            grid[x1][y] += v; 
            if(apply && !grid[x1][y]) ret += add(x1, y);
        }
    } else {
        for(int x = x1; x <= x2; x++) {
            grid[x][y1] += v;
            if(apply && !grid[x][y1]) ret += add(x, y1);
        }
    }
    return ret;
}


void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int p = id(i, j);
            uf[p] = p;
            wf[p] = 1;
        }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    init();
    for(int i = 0; i < q; i++)  {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2); x1--; y1--; x2--; y2--;
        query[i] = qry(x1, y1, x2, y2);
        paint(x1, y1, x2, y2, 1);
    }
    int comp = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(!valid(x, y)) continue;
            comp++;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(valid(nx, ny))
                    comp -= join(id(x,y), id(nx,ny));
            }
        } 
    }
    for(int i = q-1; i >= 0; i--) {
        ans[i] = comp;
        comp += paint(query[i].x1, query[i].y1, query[i].x2, query[i].y2, -1, true);       
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);

}

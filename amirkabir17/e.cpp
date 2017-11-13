#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;
int n, m;
int a[N][N];
int vis[N][N], turn;
int r1, c1, r2, c2;

void rot() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = (a[i][j] + 1) % 4;
}

bool isval(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] != turn;
}

void dfs(int i, int j) {
    vis[i][j] = turn;
        
    int ui = i-1, uj = j;
    int di = i+1, dj = j;
    int li = i, lj = j-1;
    int ri = i, rj = j+1;

    switch(a[i][j]) {
        case 0:
            if(isval(ui, uj) && (a[ui][uj] == 1 || a[ui][uj] == 2))
                dfs(ui, uj);
            if(isval(ri, rj) && (a[ri][rj] == 2 || a[ri][rj] == 3))
                dfs(ri, rj);
            break;
        case 1:
            if(isval(ri, rj) && (a[ri][rj] == 2 || a[ri][rj] == 3))
                dfs(ri, rj);
            if(isval(di, dj) && (a[di][dj] == 0 || a[di][dj] == 3))
                dfs(di, dj);
            break;
        case 2:
            if(isval(di, dj) && (a[di][dj] == 0 || a[di][dj] == 3))
                dfs(di, dj);
            if(isval(li, lj) && (a[li][lj] == 0 || a[li][lj] == 1))
                dfs(li, lj);
            break;
        case 3:
            if(isval(li, lj) && (a[li][lj] == 0 || a[li][lj] == 1))
                dfs(li, lj);
            if(isval(ui, uj) && (a[ui][uj] == 1 || a[ui][uj] == 2))
                dfs(ui, uj);
            break;
    }
}

bool can() {
    turn++;
    dfs(r1, c1);
    return vis[r2][c2] == turn;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &r1, &c1);
    scanf("%d %d", &r2, &c2);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char c;
            scanf(" %c", &c);
            a[i][j] = c-'0';
        }

    for(int i = 1; i <= 4; i++) {
        if(can()) {
            printf("%d\n", i);
            return 0;
        }
        rot();
    }
    puts("never");
}


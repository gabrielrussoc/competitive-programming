#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 33;
int n, w;
char g[N][N];
bool out[N][N];
int seen[N][N], turn;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

int wi[] = {1, 1, 1};
int wj[] = {0, 1, -1};

bool isval(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && g[i][j] == '.';
}

void forbid(int i, int j) {
    out[i][j] = true;
    for(int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if(isval(ni, nj) && !out[ni][nj]) forbid(ni, nj);
    }
}

int pour(int i, int j) {
    if(seen[i][j] == turn) return 0;
    seen[i][j] = turn;
    int ans = 1;
    for(int k = 0; k < 3; k++) {
        int ni = i + wi[k];
        int nj = j + wj[k];
        if(isval(ni, nj)) ans += pour(ni, nj);
    }
    return ans;
}

void build(int i, int j) {
    if(seen[i][j] == turn) return;
    seen[i][j] = turn;
    g[i][j] = '*';
    for(int k = 0; k < 3; k++) {
        int ni = i + wi[k];
        int nj = j + wj[k];
        if(isval(ni, nj)) build(ni, nj);
    }
}

void show() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            putchar(g[i][j]);
        putchar('\n');
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &g[i][j]);
        }
    }
    scanf("%d", &w);
    forbid(n-1, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == '.' && !out[i][j]) {
                turn++;
                int qt = pour(i, j);
                if(qt <= w) {
                    turn++;
                    build(i, j);
                    w -= qt;
                }
            }
        }
    }
    show();
}


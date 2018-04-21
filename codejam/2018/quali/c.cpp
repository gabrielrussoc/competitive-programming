#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1005;

int a, grid[N][N];

void clear(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            grid[i][j] = 0;
}

void update(int &x, int &y) {
    int around = 0;
    for(int i = x-1; i <= x+1; i++)
       for(int j = y-1; j <= y+1; j++)
           if(grid[i][j]) around++;
    if(around == 9) {
        if(a == 20) {
            if(y == 2) y = 3;
            else {
                y = 2;
                x = 4;
            }
        } else {
            if(y == 8) y = 9;
            else if(y == 9) {
                y = 2;
                x = min(x+3, 19);
            } else {
                y += 3;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        clear();
        scanf("%d", &a);
        int i = 2, j = 2;
        int x, y;
        do {
            printf("%d %d\n", i, j);
            fflush(stdout);
            scanf("%d %d", &x, &y);
            grid[x][y]++;
            update(i, j);
        } while(x != 0 && y != 0);
    }

}


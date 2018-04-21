#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 102;

int R, G, B;

struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}
    point operator-(const point &o) const {
        return point(x-o.x, y-o.y);
    }
    int operator^(const point &o) const {
        return x*o.y - y*o.x;
    }
};

int cross(const point &o, const point &a, const point &b) {
    return (a-o)^(b-o);
}

point r[N], g[N], b[N];
bitset<N> esq[2][N][N];

void clear() {
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < B; j++)
            for(int k = 0; k < B; k++)
                esq[i][j][k].reset();
}

int main() {
    int tc = 1;
    srand(time(NULL));
    while(scanf("%d %d %d", &R, &G, &B) && R != -1 && G != -1 && B != -1) {
        clear();
        int x, y;
        for(int i = 0; i < R; i++) {
            scanf("%d %d", &x, &y);
            r[i] = point(x, y);
        }
        for(int i = 0; i < G; i++) {
            scanf("%d %d", &x, &y);
            g[i] = point(x, y);
        }
        for(int i = 0; i < B; i++) {
            scanf("%d %d", &x, &y);
            b[i] = point(x, y);
        }

        for(int i = 0; i < B; i++) {
            for(int j = 0; j < B; j++){
                if(j == i) continue;
                for(int k = 0; k < R; k++) esq[0][i][j][k] = cross(b[i], b[j], r[k]) > 0;
                for(int k = 0; k < G; k++) esq[1][i][j][k] = cross(b[i], b[j], g[k]) > 0;
            }
        }

        int red = 0, green = 0;
        for(int i = 0; i < B; i++)
            for(int j = 0; j < B; j++)
                for(int k = 0; k < B; k++) {
                    if(i == j && j == k) continue;
                    int rc = (esq[0][i][j] & esq[0][j][k] & esq[0][k][i]).count();
                    int gc = (esq[1][i][j] & esq[1][j][k] & esq[1][k][i]).count();
                    if(rc > gc) red++;
                    else if(gc > rc) green++;
                }

        
        printf("Case %d: %d %d\n", tc++, red/3, green/3);

    }
}


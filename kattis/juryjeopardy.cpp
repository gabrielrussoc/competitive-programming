#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1123456;
char s[N];
int g[105][105];
int turn;

void mark(int i, int j) {
    g[i][j] = turn;
}

void update(int &d, char c) {
    if(d == 0) { //E
        if(c == 'R') d = 1;
        if(c == 'L') d = 3;
        if(c == 'B') d = 2;
    } else if (d == 1) { //S
        if(c == 'R') d = 2;     
        if(c == 'L') d = 0;
        if(c == 'B') d = 3;
    } else if (d == 2) { //W
        if(c == 'R') d = 3;     
        if(c == 'L') d = 1;
        if(c == 'B') d = 0;
    } else { //N
        if(c == 'R') d = 0;     
        if(c == 'L') d = 2;
        if(c == 'B') d = 1;
    }
}

void move(int &i, int &j, int d) {
    if(d == 0) j++;
    if(d == 1) i++;
    if(d == 2) j--;
    if(d == 3) i--;
}

bool fail(int i, int j, int p) {
    if(i == p && j == 0) return false;
    if(i <= 0 || j <= 0) return true;
    if(i >= 99 || j >= 99) return true;
    return false;
}


bool can(int p) {
    int d = 0; //E S W N
    int i = p, j = 0;
    for(int k = 0; s[k]; k++) {
        char c = s[k];
        update(d, c);
        move(i, j, d);
        if(fail(i, j, p)) return false;
    }
    if(i != p && j != 0) return false;
    return true;
}

void build(int p) {
    int d = 0;
    int i = p, j = 0;
    int mi = 999, mj = 999, Mi = 0, Mj = 0;
    for(int k = 0; s[k]; k++) {
        char c = s[k];
        update(d, c);
        move(i, j, d);
        mark(i, j);
        mi = min(i, mi);
        mj = min(j, mj);
        Mi = max(i, Mi);
        Mj = max(j, Mj);
    }
    int n = Mi - mi + 3;
    int m = Mj - mj + 2;
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == turn) putchar('.');
            else putchar('#');
        }
        putchar('\n');
    }
}


int main() {
    int t;
    scanf("%d",&t);
    printf("%d\n", t);
    while(t--) {
        turn++;
        scanf(" %s", s);
        for(int i = 1; ; i++) {
            if(can(i)) {
                build(i);
                break;
            }
        }
    }
}

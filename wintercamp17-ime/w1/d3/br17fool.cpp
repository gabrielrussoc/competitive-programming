#include <bits/stdc++.h>
#define pb push_back
#define set uaeshsueh
#define list hhusdf
using namespace std;
typedef long long ll;

const int N = 205;

int t, n;
int turn, vis[N][N];
bool memo[N][N];
char s[N];

bool set(int i, int j);

bool atom(int i, int j) {
    return i == j && (s[i] == '{' || s[i] == '}' || s[i] == ',');
}

bool element(int i, int j) {
    return atom(i, j) || set(i, j);
}

bool list(int i, int j) {
    bool &me = memo[i][j];
    if(vis[i][j] == turn) return me;
    vis[i][j] = turn;
    if(vis[i][j] == turn) 
    if(element(i, j)) return me = true;
    for(int k = i+1; k < j; k++) {
        if(s[k] != ',') continue;
        if(element(i, k-1) && list(k+1, j)) return me = true;
    }
    return me = false;
}

bool elementlist(int i, int j) {
    if(i > j) return true;
    return list(i, j);
}

bool set(int i, int j) {
    return s[i] == '{' && s[j] == '}' && elementlist(i+1, j-1);
}

int main() {
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        turn++;
        scanf(" %s", s);
        n = strlen(s);
        printf("Word #%d: %sSet\n", tc, set(0, n-1) ? "" : "No ");
    }
}


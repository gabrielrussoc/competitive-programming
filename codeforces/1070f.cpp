#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 400005;

int v[5][N], acc[N];
int sz[5];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        char x, y;
        scanf(" %c%c %d",&x, &y, &a);
        int idx = ((x-'0')<<1) + (y-'0');
        v[idx][sz[idx]++] = a;
    }
    for(int i = 0; i < 4; i++) sort(v[i], v[i]+sz[i], greater<int>());
    for(int i = 0; i < n; i++) acc[i+1] = acc[i] + v[0][i];
    int ans = 0;
    for(int i = 0; i < sz[3]; i++) ans += v[3][i];
    for(int i = 0; i < min(sz[1], sz[2]); i++) ans += v[1][i] + v[2][i];

    if(sz[1] < sz[2]) {
        int loc = 0;
        int left = sz[3];
        loc = acc[left];
        int vc = 0;
        for(int i = 0; i < left; i++) {
            vc += v[2][i+sz[1]];
            loc = max(loc, vc + acc[left-i-1]);
        }
        ans += loc;
    } else {
        int loc = 0;
        int left = sz[3];
        loc = acc[left];
        int vc = 0;
        for(int i = 0; i < left; i++) {
            vc += v[1][i+sz[2]];
            loc = max(loc, vc + acc[left-i-1]);
        }
        ans += loc;
    }

    printf("%d\n", ans);
}


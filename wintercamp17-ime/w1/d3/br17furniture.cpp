#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;
int v[N], p[N], o[N], n;

const int inf = 0x3f3f3f3f;

bool ordered() {
    for(int i = 0; i < n; i++) {
        if(p[o[i]] != i) return false;
    }
    return true;
}

int main() {
    n = 0;
    while(scanf("%d", v+n) != EOF) n++;
    for(int i = 0; i < n/2; i++) p[i] = v[i + n/2]; 
    n /= 2;
    for(int i = 0; i < n; i++) o[i] = i;
    int ans = 0;

    for(int i = 0; i < n; i++) if(p[o[i]] != i) ans += v[o[i]];
    while(true) {
        if(ordered()) break;
        int bi, bj, cost = inf;
        for(int i = 0; i < n; i++) {
            if(i != p[o[i]]) {
                int j = p[o[i]];
                int loc = 0;
                if(p[o[j]] != i) loc = v[o[j]]; 
                if(loc < cost) {
                    cost = loc;
                    bi = i;
                    bj = j;
                }
            }
        }
        ans += cost;
        swap(o[bi], o[bj]);
    }
    printf("%d\n", ans);
    
}


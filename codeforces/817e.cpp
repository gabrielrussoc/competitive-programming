#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3000006;
int trie[N][2], sz[N], ts = 1;

void update(int p, int v) {
    int r = 1;
    sz[r] += v;
    for(int i = 31; i >= 0; i--) {
        bool c = (1<<i)&p;
        if(!trie[r][c]) trie[r][c] = ++ts;
        r = trie[r][c];
        sz[r] += v;
    }
}

int query(int p, int l) {
    int r = 1;
    int ans = 0;
    for(int i = 31; i >= 0; i--) {
        if(!r) break;
        bool pc = (1<<i)&p;
        bool lc = (1<<i)&l;
        if(lc == 0) r = trie[r][pc];
        else {
            ans += sz[trie[r][pc]];
            r = trie[r][!pc];
        }
    }
    return ans;
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int t, p, l;
        scanf("%d %d", &t, &p);
        switch(t) {
            case 1:
                update(p, 1);
                break;
            case 2:
                update(p, -1);
                break;
            case 3:
                scanf("%d", &l);
                printf("%d\n", query(p, l));
                break;
        }
    }
}


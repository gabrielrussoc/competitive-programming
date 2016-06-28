#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define end asueh
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100004;
const int modn = 1000000007;

int tc, n;
char s[13];
int ts, t;
int child[12][N];
bool end[N];

bool isLeaf (int t) {
    for(int i = 0; i < 10; i++) if(child[i][t] != -1) return false;
    return true;
}

int insert (int t, char *s, int i, int n) {
    if (t == -1) {
        ++ts;
        for(int j = 0; j < 10; j++) child[j][ts] = -1;  
        end[ts] = false;
        t = ts;
    }
    if(i == n) {
        end[t] = true;
        return t;
    }
    child[s[i]-'0'][t] = insert(child[s[i]-'0'][t], s, i+1, n);
    return t;
}

int main() {
    scanf("%d",&tc);
    while(tc--) {
        ts = 0;
        scanf("%d",&n);
        for(int i = 0; i < 10; i++) child[i][0] = -1;
        end[0] = false;
        for(int i = 0; i < n; i++) {
            scanf(" %s",s);
            insert(0, s, 0, strlen(s));
        }
        bool ans = true;
        for(int i = 1; i <= ts && ans; i++)
            if (end[i] && !isLeaf(i)) {
                ans = false;
            }
        if(ans) puts("YES");
        else puts("NO");
    }
}


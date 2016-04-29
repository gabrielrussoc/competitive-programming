#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;

int p;
int memo[N][4];
int visi[N][4];
set<string> ans;
char v[N];

int dp (int i, int t) {
    if(i < 5) return 0;
    int &me = memo[i][t];
    if(visi[i][t]) return me;
    visi[i][t] = 1;
    /*2*/
    int a = 0;
    if(t == 1) {
        if(v[i-2] != v[i] || v[i-1] != v[i+1]) a |= dp(i-2,1);
    } else a |= dp(i-2,1);
    if(a) {
        char gg[5];
        gg[0] = v[i-2];
        gg[1] = v[i-1];
        gg[2] = 0; 
        string x = gg;
        ans.insert(gg);
    }

    int b = 0;
    /*3*/
    if(t == 2) {
        if(v[i-3] != v[i] || v[i-2] != v[i+1] || v[i-1] != v[i+2]) b |= dp(i-3,2);
    } else b |= dp(i-3, 2);
    if(b) {
        char gg[5];
        gg[0] = v[i-3];
        gg[1] = v[i-2];
        gg[2] = v[i-1];
        gg[3] = 0;
        string x = gg;
        ans.insert(gg);
    }
    return me = 1;
}


int main() {
    scanf(" %s", v);
    int n = strlen(v);
    dp(n,0);
    cout << ans.size() << endl;
    for(string s : ans)
        cout << s << endl;
}


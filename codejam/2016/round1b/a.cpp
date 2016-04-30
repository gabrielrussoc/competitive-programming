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
const int N = 2004;
const int modn = 1000000007;

char s[N];
int n;
char v[] = "ZXWSVFONIH";
int p[] = {0,6,2,7,5,4,1,9,8,3};
char g[][13] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
multiset<int> ans;
string ss;

bool has (char c) {
    for(int i = 0; i < n; i++) if(s[i] == c) return true;
    return false;
}

bool match (int j) {
    for(int i = 0; i < ss.size(); i++)
        if(s[j] == ss[i]) {
            ss[i] = '#';
            return true;
        }
    return false;
}

void remove(int i) {
    ss = g[i];
    for(int j = 0; j < n; j++){
        if(match(j))
            s[j] = '$';
    }
}

void solve(){
    for(int i = 0; i < 10; i++) {
        while(has(v[i])){
            remove(p[i]);
            ans.insert(p[i]);
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);  
    for(int tc = 1; tc <= t; tc++) {
        ans.clear();
        scanf(" %s",s);
        n = strlen(s);
        printf("Case #%d: ", tc);
        solve();
        for(int x : ans) printf("%d",x);
        putchar('\n');
    }
}


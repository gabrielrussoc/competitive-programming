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
const int N = 100004;
const int modn = 1000000007;


int main() {
    int t, k;
    scanf("%d",&t);
    while(t--){
        vector<int> ans;
        scanf("%d",&k);
        if(k == 1) {
            puts("1\n1");
            continue;
        }
        int lg2 = 31-__builtin_clz(k);
        int x = 6969;
        int y = 1;
        for(int i = 0; i < lg2; i++) {
            ans.pb(x+1); ans.pb(x); x += 2;
            if((1<<(lg2-i-1))&k)
                while(y <= i+1) ans.pb(y++); 
        }
        printf("%d\n",ans.size());
        for(int i : ans) printf("%d ", i >= 6969 ? i-6969+y : i);
        putchar('\n');
    }

}


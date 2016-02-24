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

multiset<int> s;
int x, n, a[25];

bool solve (){
    auto it = s.begin();
    int p,q,f;
    bool xab;
    p = *(it++); q = *(it++);
    for(; it != s.end(); it++){
        xab = false;
        multiset<int> t = s;
        f = *it;
        if((p+q-f) & 1) continue;
        a[0] = (p+q-f)/2; a[1] = p-a[0]; a[2] = q-a[0];
        t.erase(a[0]+a[1]); t.erase(a[0]+a[2]); t.erase(a[1]+a[2]);
        for(int i = 3; i < n && !xab; i++) {
            a[i] = *(t.begin()) - a[0];
            for(int j = 0; j < i && !xab; j++) {
                if(!t.count(a[i]+a[j])) xab = true;
                if(!xab) t.erase(a[i]+a[j]);
            }
        }
        if(!xab) {
            for(int i = 0; i < n; i++) printf("%d ",a[i]);
            putchar('\n');   
            return true;
        }
    }
    return false;
}

int main() {
    while(scanf("%d",&n) != EOF) {
        s.clear();
        int k = (n*(n-1))/2;
        for(int i = 0; i < k; i++) {
            scanf("%d",&x);
            s.insert(x);
        }
        if(!solve()) puts("Impossible");
    }
}


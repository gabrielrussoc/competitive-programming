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

set<int> lin, col;
int n, m;

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        lin.insert(a);
        col.insert(b);
        cout << ll(ll(n - lin.size()) * ll(n - col.size())) << " ";
    }
    cout << endl;
}


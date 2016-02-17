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
const int N = 100006;
const int modn = 1000000007;

int n;
int v[N];

int main() {
    scanf("%d",&n);
    v[0] = 1;
    n--;
    int at = 1;
    while(n--){
        v[at] = 1;
        while(v[at] == v[at-1] && at > 0) {
            at--;
            v[at]++;
        }
        at++;
    }
    for(int i = 0; i < at; i++) printf("%d ",v[i]);
    putchar('\n');
}


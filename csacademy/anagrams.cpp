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
const int N = 100005;
const int modn = 1000000007;

int n;
string ss;
char s[N];
map<string, int> m;

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        cin >> ss;
        sort(ss.begin(), ss.end());
        m[ss]++;
    }
    int maxi = 0;
    for(map<string,int>::iterator it = m.begin(); it != m.end(); it++)
        maxi = max(maxi,it->second);
    
    printf("%d\n",maxi);
}


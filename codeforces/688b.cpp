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

char s[N];
 
int main() {
    scanf(" %s",s);
    int n = strlen(s);
    printf("%s",s);
    for(int i = n-1; i >= 0; i--) putchar(s[i]);
    putchar('\n');
}


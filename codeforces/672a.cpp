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

char s[N];

int dig(int x) {
    int ret = 0;
    while(x) {
        x /= 10;
        ret++;
    }
    return ret;
}

int main() {
    int i = 1;
    int count = 0;
    while(count < N) {
        sprintf(s+count, "%d",i);
        count += dig(i);
        i++;
    }
    int n;
    scanf("%d",&n);
    printf("%c\n",s[n-1]);
    
}


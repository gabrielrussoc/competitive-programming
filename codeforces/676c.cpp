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
    int n, k;
    char s[N];
    scanf("%d %d",&n, &k);
    scanf(" %s",s);
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        int a, b, ans = inf;
        a = b = 0;
        for(int i = 0; i < mid; i++) {
            if(s[i] == 'a') a++;
            else b++;
        }
        ans = min(ans, min(a,b));
        for(int i = 1; i <= n-mid; i++) {
            if(s[i-1] == 'a') a--;
            else b--;
            if(s[i+mid-1] =='a') a++;
            else b++;
            ans = min(ans, min(a,b));
        }
        if(ans <= k) lo = mid;
        else hi = mid-1;
    }
    printf("%d\n",lo);
}


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

int t;
char s[123];

char shift (char c) {
    if(c == '+') return '-';
    return '+';
}

void flip(int k) {
    for(int i = 0; i < k/2; i++)
        swap(s[i], s[k-i-1]);
    for(int i = 0; i < k; i++)
        s[i] = shift(s[i]);
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf(" %s",s);
        int n = strlen(s);
        int ans = 0;
        while(1) {
            char f = s[0];
            int i = 1;
            while (i < n && s[i] == f) i++;
            if(i == n && f == '+') break;
            flip(i);
            ans++;
        }
        printf("Case #%d: %d\n",tc,ans);
    }
}


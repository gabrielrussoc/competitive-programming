#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 107;
char s[N];
int f[N];

int main() {
    scanf(" %s",s);
    for(int i = 0; s[i]; i++) f[s[i]-'a'] += (i+1);
    ll ans = 0;
    sort(f, f+26, greater<int>());
    for(int i = 0; i < 26; i++) {
        if(f[i] == 0) break;
        ans += ll(26-i) * ll(f[i]);
    }
    printf("%lld\n", ans);
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

char s[123];

ll get(char c) {
    if(c >= 'd') return 'f'-c+1;
    else return c-'a'+1+3;
}

int main() {
    scanf(" %s", s);
    int n = strlen(s);
    char seat = s[n-1];
    s[n-1] = 0;
    ll row = atoll(s);
    row--;
    ll pos = row/2ll;
    if (pos&1ll) pos += (row%2ll) - 1ll;
    else pos += (row % 2ll);
    ll walk = row;
    if((row/2ll)&1ll) walk -= 2ll;
    printf("%lld\n",pos*6ll+ walk + get(seat));
}


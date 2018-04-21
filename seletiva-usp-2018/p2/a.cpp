#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

enum suit {SPADES, HEARTS, DIAMONDS, CLUBS};
const int N = 55;

int mask;
vector<suit> order = {SPADES, HEARTS, DIAMONDS, CLUBS};

bool ascending(suit s) {
    return (1<<s)&mask;
}

int where(suit s) {
    for(int i = 0; i < 4; i++)
        if(order[i] == s)
            return i;
    return 0;
}

int get_value(char c) {
    if(c >= '2' && c <= '9') return c-'0';
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return 14;
}

suit get_suit(char c) {
    if(c == 's') return SPADES;
    if(c == 'h') return HEARTS;
    if(c == 'd') return DIAMONDS;
    return CLUBS;
}

struct card {
    int v, i;
    suit s;
    card() {}
    card(int _v, suit _s, int _i) : v(_v), i(_i), s(_s) {}
    bool operator<(const card &o) const {
        if(s == o.s) return ascending(s) ? v < o.v : v > o.v;
        return where(s) < where(o.s);
    }
} a[N];

int n, dp[N];

int lis() {
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], 1 + dp[j]);
    }
    return *max_element(dp, dp+n);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char v, s;
        scanf(" %c%c", &v, &s);
        a[i] = card(get_value(v), get_suit(s), i);
    }
    int ans = n;
    do {
        for(mask = 0; mask < (1<<4); mask++)
            ans = min(ans, n-lis());
    } while(next_permutation(order.begin(), order.end()));
    printf("%d\n", ans);
}


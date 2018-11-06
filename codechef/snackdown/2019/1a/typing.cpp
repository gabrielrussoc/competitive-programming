#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 35;
char s[N];
int n;

int hand(char c) {
    if(c == 'd' || c == 'f') return 0;
    if(c == 'j' || c == 'k') return 1;
    return -1;
}

bool same(char a, char b) {
    return hand(a) == hand(b);
}

map<string, int> memo;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memo.clear();
        scanf("%d", &n);
        int ans = 0;
        while(n--) {
            scanf(" %s", s);
            string ss = s;
            if(memo.count(ss)) {
                ans += memo[ss]/2;
                continue;
            }
            int cur = 0;
            char last = 'x';
            for(int i = 0; s[i]; i++) {
                if(same(last, s[i])) cur += 4;
                else cur += 2;
                last = s[i];
            }
            memo[ss] = cur;
            ans += cur;
        }
        printf("%d\n", ans);
    }
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n;
char s1[N], s2[N];

int main() {
    scanf(" %d %s %s", &n, s1, s2);
    int ans = 0;
    bool f = false;
    for (int i = 0; s1[i] != 0; i++) {
        if (s1[i] != s2[i]) {
            f = true;
        } else if (f) {
            ans++;
            f = false;
        }
    }
    if (f) ans++;
    printf("%d\n", ans);
}
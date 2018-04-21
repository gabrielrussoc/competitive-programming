#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 33;

int t, d, n;
char s[N];

bool impossible() {
    int shoot = 0;
    for(int i = 0; s[i]; i++)
        if(s[i] == 'S') shoot++;
    return shoot > d;
}

int value() {
    int cur = 1;
    int val = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == 'C') cur *= 2;
        else val += cur;
    }
    return val;
}

void reduce() {
    for(int i = n-2; i >= 0; i--) {
        if(s[i] == 'C' && s[i+1] == 'S') {
            swap(s[i], s[i+1]);
            return;
        }
    }
}

int main() {
    int tc = 1;
    scanf("%d", &t);
    while(t--) {
        printf("Case #%d: ", tc++);
        scanf("%d %s", &d, s);
        n = strlen(s);
        if(impossible()) puts("IMPOSSIBLE");
        else {
            int ans = 0;
            while(value() > d) {
                reduce();
                ans++;
            }
            printf("%d\n", ans);
        }
    }

}


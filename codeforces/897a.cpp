#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, m;
char s[199];

int main() {
    scanf("%d %d", &n, &m);
    scanf(" %s", s);
    while(m--) {
        int l, r;
        char c1, c2;
        scanf("%d %d", &l, &r); l--;
        scanf(" %c %c", &c1, &c2);
        for(int i = l; i < r; i++)
            if(s[i] == c1) s[i] = c2;
    }
    puts(s);
}


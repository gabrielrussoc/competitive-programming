#include <bits/stdc++.h>
#define pb push_back
#define stack aeuheah
using namespace std;
typedef long long ll;

const int N = 112345;
char stack[N];
char s[N];
int n, k, qt[N], ps;

int main() {
    scanf("%d %d",&n, &k);
    scanf(" %s",s);
    for(int i = 0; s[i]; i++) {
        if(!ps) stack[ps] = s[i], qt[ps++] = 1;
        else {
            if(stack[ps-1] == s[i]) stack[ps] = s[i], qt[ps] = 1 + qt[ps++-1];
            else stack[ps] = s[i], qt[ps++] = 1;
        }
        if(qt[ps-1] == k) {
            for(int j = 0; j < k; j++) ps--;
        }
    }
    for(int i = 0; i < ps; i++) putchar(stack[i]);
    putchar('\n');
}

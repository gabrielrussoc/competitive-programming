#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2007;
bool f[N];

int main() {
    f[0] = f[1] = true;
    int f1 = 0, f2 = 1;
    while(f1 + f2 < 1005) {
        int nf = f1+f2;
        f1 = f2;
        f2 = nf;
        f[nf] = true;
    }
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        putchar(f[i] ? 'O' : 'o');
    }
    putchar('\n');
    
}


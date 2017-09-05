#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int mdc(int a, int b) {
    return b ? mdc(b, a%b) : a;
}

int main() {
    int n;
    scanf("%d",&n);
    int f;
    scanf("%d", &f);
    for(int i = 0; i < n-1; i++) {
        int a;
        scanf("%d", &a);
        int d = mdc(a,f);
        printf("%d/%d\n", f/d, a/d);
    }
}


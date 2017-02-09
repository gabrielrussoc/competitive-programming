#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;
int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    b[n/2] = a[n/2];
    for(int i = 0; i < n/2; i++) {
        if(i&1) b[i] = a[i], b[n-i-1] = a[n-i-1];
        else b[i] = a[n-i-1], b[n-i-1] = a[i];
    }
    for(int i = 0; i < n; i++) printf("%d ", b[i]);
    putchar('\n');
}


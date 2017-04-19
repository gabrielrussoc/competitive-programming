
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, max_a = 0, max_b = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        if (b > max_b && a > max_a) 
            max_b = b;
        max_a = max(max_a, a);
    }
    printf("%d\n", max_b);
}
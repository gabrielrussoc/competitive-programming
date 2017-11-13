#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);
    for (int i = n; i > k; i--) printf("%d ", i);
    for (int i = 1; i <= k; i++) printf("%d%c", i, (i == k) ? '\n' : ' ');
}


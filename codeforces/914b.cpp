#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N], f[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        f[a[i]]++;
    }
    sort(a, a+n, greater<int>());
    for(int i = 0; i < n; i += f[a[i]]) {
        if(f[a[i]]&1) {
            puts("Conan");
            return 0;
        }
    }
    puts("Agasa");
}


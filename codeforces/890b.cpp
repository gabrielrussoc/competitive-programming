#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;
const int inf = 0x3f3f3f3f;
int last[N], n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < N; i++) last[i] = inf;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        last[a] = i;
    }
    printf("%d\n", min_element(last, last+N) - last);
}


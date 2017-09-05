#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    srand(time(NULL));
    puts("1");
    int n = rand() % 1000 + 1;
    printf("%d\n", n);
    vector<pii> v;
    for(int i = 0; i < n; i++) {
        int x = rand() % 1000 ;
        int r = rand() % 1000;
        v.pb(pii(x, r));
    }
    sort(v.begin(), v.end());
    for(pii a : v) {
        printf("%d %d\n", a.first, a.second);
    }
}


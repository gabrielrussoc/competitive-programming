#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1234;
int n;
double d;

int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%lf %d", &d, &n);
        double ans = 1 / 0.;
        for(int i = 0; i < n; i++) {
            double k, s;
            scanf("%lf %lf", &k, &s);
            double arr = (d - k) / s;
            ans = min(ans, d / arr);
        }
        printf("Case #%d: %.20lf\n", tc, ans);
    }
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1005;

int n;
double r, x[N], y[N];

int main() {
    scanf("%d %lf", &n, &r);
    for(int i = 0; i < n; i++) scanf("%lf", x+i);
    
    y[0] = r;
    for(int i = 1; i < n; i++) {
        y[i] = r;
        for(int j = 0; j < i; j++) {
            double d = fabs(x[j]-x[i]);
            if(d <= 2. * r) {
                y[i] = max(y[i], y[j] + sqrt(-d*d + 4.*r*r));
            }
        }

    }
    for(int i = 0; i < n; i++) printf("%.20lf ", y[i]);
    puts("");

}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;

int n;
ll p[N], v[7], sum, freq[7];

void take(int j) {
    ll qt = sum / v[j];
    freq[j] += qt;
    sum -= qt * v[j];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", p+i);
    for(int i = 0; i < 5; i++) scanf("%lld", v+i);

    for(int i = 0; i < n; i++) {
        sum += p[i];
        for(int j = 4; j >= 0; j--) take(j);
    }
    for(int i = 0; i < 5; i++) printf("%lld ", freq[i]);
    printf("\n%lld\n", sum);
    
}


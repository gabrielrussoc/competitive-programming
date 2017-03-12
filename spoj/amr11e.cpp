#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int ans[N], primes[N], p[N], ps;

bool lucky(int n) {
    int cont = 0;
    for(int i = 0; i < ps; i++) if(n%primes[i] == 0) cont++;
    return cont > 2;
}

int main() {
    int t;
    scanf("%d", &t);
    int num = 30;

    for(int i = 2; i*i < N; i++)
        if(!p[i])
            for(int j = i*i; j < N; j += i)
                p[j] = 1;

    for(int i = 2; i < N; i++) if(!p[i]) primes[ps++] = i;
    
    int cont = 0;
    while(cont < 1000) {
        if(lucky(num)) ans[cont++] = num;
        num++;
    }

    while(t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n", ans[n-1]);
    }
}
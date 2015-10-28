#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    while (scanf ("%d", &n) != EOF) {
        int ans = 1;
        int aux = n;
        for (int i = 2; i * i <= n; i++) {
            int cont = 0;
            while (n % i == 0) {
                n /= i;
                if(i != 2) cont++;
            }
            ans *= cont;
        }
        if(n != 1) ans *= 2;
        printf("%d\n",aux/2 - ans+1);
    }
}

#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    while (scanf ("%d", &n) != EOF) {
        int ans = 1;
        for (long long i = 2; i * i <= n; i++) {
            int cont = 0;
            while (n % i == 0) {
                n /= i;
                cont++;
            }
            if(cont){
                ans *= i-1;
                for(int j = 0; j < cont-1; j++)
                    ans *= i;
            }
        }
        if(n != 1) ans *= n-1;
        printf("%d\n",ans/2);
    }
}

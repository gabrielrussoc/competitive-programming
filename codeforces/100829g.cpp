#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

char s[333];

int sum(int k){
    int ans = 0;
    while(k) {
        ans += k%10;
        k /= 10;
    }
    return ans;
}

int main() {
    while(scanf(" %s", s) && strcmp(s, "END")) {
        int n = atoi(s);
        int k = n-1;
        int s = sum(n);
        while(true){
            if(s-sum(k) == 1) {
                printf("%d\n", k);
                break;
            }
            k--;
        }
    }
}
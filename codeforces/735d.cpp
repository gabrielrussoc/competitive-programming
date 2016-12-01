#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n;

bool isp(int k) {
    for(int i = 2; i*i <= k; i++)
        if(k%i == 0) return false;
    return true;
}

int solve(int n) {
    if(isp(n)) return 1;
    if(n%2 == 0) return 2;
    if(isp(n-2)) return 2;
    return 3;
}

int main() {
    scanf("%d",&n);
    printf("%d\n",solve(n));
}


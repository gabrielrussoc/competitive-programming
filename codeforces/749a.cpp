#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int ans[N], k, cont;

int main() {
    scanf("%d",&k);
    while(k > 3) {
        ans[cont++] = 2;
        k -= 2;
    }
    ans[cont++] += k;
    printf("%d\n",cont);
    for(int i = 0; i < cont; i++) printf("%d ",ans[i]);
    putchar('\n');
}


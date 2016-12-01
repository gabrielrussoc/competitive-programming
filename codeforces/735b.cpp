#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int n, n1, n2;
int a[N];

int main() {
    scanf("%d %d %d",&n,&n1,&n2);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    sort(a,a+n);
    if(n1 > n2) swap(n1, n2);
    double r1, r2;
    r1 = r2 = 0;
    for(int i = n-1; i >= n-n1; i--)
        r1 += double(a[i]);
    for(int i = n-n1-1; i >= n-n1-n2; i--)
        r2 += double(a[i]);
    printf("%.20lf\n",r1/double(n1) + r2/double(n2));
}


#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;

int main() {
    int n;
    scanf("%d",&n);
    int mini, maxi;
    mini = 0;
    maxi = 0;
    int p, q;
    p = 2;
    q = 0;
    for(int i = 0; i < n; i++) {
        if(p < 2) mini++;
        if(q < 2) maxi++; 
        p = (p+1)%7;
        q = (q+1)%7;
    }
    printf("%d %d\n",mini,maxi);
}


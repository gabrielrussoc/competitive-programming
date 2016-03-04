#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define div ahuehea
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 1000004;
const int modn = 1000000007;
typedef unsigned long long hash;

int n, k, div[N];
hash h[N], X = 33, x[N]; 
char s[N];

void getdiv (){
    k = 0;
    for(int i = 1; i <= n; i++)
        if(n%i == 0) div[k++] = i;
}

int cv(char c){
    return c-'!'+1;
}

hash calc(int i, int j) {
    return h[j+1] - h[i]*x[j-i+1];
}

int check(int w) {
    int i = 0;
    while(i < n) {
        int p = w;
        hash at = calc(0,p-1);
        while(2*p <= n-i) {
            at = at + at*x[p];     
            p *= 2;
        }
        if(at != calc(i,i+p-1)) return 0;
        i += p;
    }
    return 1;
}

int main() {
    x[0] = 1;
    while(scanf(" %s",s)) {
        if(s[0] == '.' && !s[1]) break;
        n = strlen(s);
        getdiv();
        for(int i = 0; i < n; i++) {
            h[i+1] = h[i]*X + cv(s[i]);
            x[i+1] = x[i]*X;
        }
        for(int i = 0; i < k; i++) 
            if(check(div[i])) { printf("%d\n",n/div[i]); break; }
        
    }
}


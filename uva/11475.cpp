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
const int N = 100004;
const int modn = 1000000007;

typedef unsigned long long hash;

const hash p = 33;
char s[N];
hash he[N], hd[N], x[N];

int cv (char c){return c-'a'+1;}

hash calce (int i, int j){
    return he[j+1] - he[i]*x[j-i+1];
}
hash calcd (int i, int j){
    return hd[j+1] - hd[i]*x[j-i+1];
}

int main() {
    while(scanf(" %s",s) != EOF){
        int n = strlen(s);
        x[0] = 1;
        for(int i = 1; i <= n; i++){
            he[i] = he[i-1]*p + cv(s[i-1]);
            hd[i] = hd[i-1]*p + cv(s[n-i]);
            x[i] = p*x[i-1];
        }
        for(int i = 0; i < n; i++){
            if(calce(i,n-1) == calcd(0,n-i-1)) {
                printf("%s",s);
                for(int j = i-1; j >= 0; j--)
                    printf("%c",s[j]);
                putchar('\n');
                break;
            }                
        }
    }
}


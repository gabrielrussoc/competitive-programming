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
const int N = 200007;
const int modn = 1000000007;

char s[N];

void troca(int l, int r) {
    int tam = r-l+1;
    if(tam == 1) return;
    if(tam&1) {
        for(int i = l+1; i <= r; i += 2)
            s[i] = s[i] == 'x' ? 'p' : 'x';
    } else {
        char c = 'x';
        if((l && s[l-1] == 'x') || s[l+1] == 'x'){
            c = 'p';
            if((l && s[l-1] == 'p') || s[l+1] == 'p')
                c = 'w';
        }
        for(int i = l; i < r; i += 2)  
            s[i] = c;
    }
}

int main() {
    scanf(" %s",s);
    int n = strlen(s);
    int j = 0;
    for(int i = 0; i <= n; i++) {
        if(s[i] != s[j]) {
            troca(j,i-1);
            j = i;
        }
    }
    puts(s);

}


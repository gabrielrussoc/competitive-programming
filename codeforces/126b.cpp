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
const int N = 1000004;
const int modn = 1000000007;

char s[N];
int z[N];
int n;

int main() {
    scanf(" %s",s);
    n = strlen(s);
    int l,r;
    l = r = 0;
    for(int i = 1; i < n; i++){
        if(i > r){ 
            l = r = i;
            while(r < n && s[r] == s[r-l]) r++;
            z[i] = r-l; r--;
        } else {
            int k = i-l;
            if(z[k] < r-i+1) z[i] = z[k];
            else {
                l = i; 
                while(r < N && s[r] == s[r-l]) r++;
                z[i] = r-l; r--;  
            }
        }
    }

    int mz = 0;
    for(int i = 1; i < n; i++){
        if(z[i] == n-i && mz >= n-i){    
            for(int j = i; j < n; j++) printf("%c",s[j]);
            putchar('\n');
            return 0;
        }
        mz = max(mz,z[i]);
    }
    puts("Just a legend");
}

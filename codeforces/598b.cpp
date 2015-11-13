#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-8;
const int inf = INT_MAX;
const int modn = 1000000007;

//////////////0123456789
const int N = 10004;

int main(){
    char s[N],aux[N];
    scanf(" %s",s);
    int m;
    scanf("%d",&m);    
    for(int i = 0; i < m; i++){
        int l, r, k;
        scanf("%d %d %d",&l,&r,&k);
        l--, r--;
        int t = r-l+1;       
        k %= t;
        for(int j = 0; j < t; j++){
            aux[(j+k)%t + l] = s[j+l];
        }
        for(int j = l; j <= r; j++){
            s[j] = aux[j];
        }
    }
    printf("%s\n",s);
}

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define ff first
#define ss second
using namespace std;
typedef long long ll;

//////////////0123456789
const int N = 100005;
const int modn = 1000000007;

char s[N];
int n;

int main(){
    scanf("%d",&n);
    scanf(" %s",s);
    int ans=1, j=0;
    int ant = s[0]-'0';
    for(int i = 1; s[i] != 0; i++){
        if(s[i]-'0' != ant){
            ans++;
            ant = s[i]-'0';
        }
        else j++;
    }
    if(ans != n) ans = ans + 1 + (j>1);
    printf("%d\n",ans);
}

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
const int N = 100009;
const int A = 1000009;
const int modn = 1000000007;

int main (){
    int x, ans = 0;
    char s[30];
    scanf("%d %s",&x,s);
    scanf("%s",s);
    if(s[0] == 'm'){
        if(x < 30) ans = 12;
        else if(x < 31) ans = 11; 
        else ans = 7;
    } else {
        int count;
        if(x < 5) count = x+2;
        else count = x-5;
        while(count < 366) ans++, count += 7;
    }
    printf("%d\n",ans);
}

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MODN = 1000000007;

char n[105], s[100005];
int k,p;
ll m[100005];

bool pode(int i, int j){
    if(j-i+1 > p) return false;
    if(p > j-i+1) return true;

    for(int l = 0; l < p; l++)
        if(s[l+i] != n[l]) return s[l+i] < n[l];
    return true;
}

ll pd(int i){

    if(i == k) return 1;
    if(i > k || s[i] == '0') return 0;
    if(m[i] != -1) return m[i];
    ll ans = 0;
    for(int j = i; j < min(i+100,k); j++){
        if(pode(i,j)){
            ans += pd(j+1);
            ans %= MODN;
        }
    }
    ans %= MODN;
    m[i] = ans;
    return ans;
}

int main(){
    
    memset(m,-1,sizeof m);
    cin >> n >> s;
    k = strlen(s);
    p = strlen(n);
    ll ans = pd(0);
    cout << ans << endl;

}

//autor: nathanpro
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
 
const ll M = (1e9 + 7);
struct mod{
    ll x;
    mod () { x = 0; }
    mod (ll y) { x = y; }
    mod operator+(mod b){ return (x+b.x)%M; }
    mod operator*(mod b){ return (x*b.x)%M; }
};
 
const int N = 200000;
 
int T, n;
ll a[N];
mod S[N], P[N], Q[N];
 
int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
 
        P[n-1] = P[n] =  1;
        Q[n-1] = a[n-1];
        S[n-1] = a[n-1];
        for(int i=n-2;0<=i;i--){
            Q[i] = mod(a[i])*(Q[i+1] + P[i+1]);
            P[i] = mod(2)*P[i+1];
            S[i] = mod(a[i]-1)*Q[i+1] + mod(a[i])*P[i+1] + mod(2)*S[i+1];
        }
        cout << S[0].x << endl;
    }
}


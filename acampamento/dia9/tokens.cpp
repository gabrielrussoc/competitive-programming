#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

ll n,a,b;


int main(){

    ll v[100006];
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 0; i < n; i++){
        ll lo, hi,mid;
        lo = 0; hi = v[i];
        ll maxd = v[i]*a/b;
        while(hi != lo){
            mid = (lo+hi)/2;
            if(mid*a/b >= maxd)
                hi = mid;
            else
                lo = mid+1;   
        }
        cout << v[i]-lo << ' ';
     }
    cout << endl;

}

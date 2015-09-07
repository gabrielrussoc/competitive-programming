#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<long long,long long> freq;
map<long long,long long> pa;

long long n,k,x;

int main(){
    cin >> n >> k;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans += pa[x];
        if(x%k == 0) pa[x*k] += freq[x/k];
        freq[x]++;
    }
    cout << ans << endl;
}

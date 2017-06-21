#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n;
ll a[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int i = 0, j, k;
    while(i < n && a[i] == a[0]) i++;
    j = i;
    while(j < n && a[j] == a[1]) j++;
    k = j;
    while(k < n && a[k] == a[2]) k++; 

    if(i >= 3) {
        ll n = i;
        cout << n * (n-1ll) * (n-2ll) / 6ll << endl;
    } else if(j >= 3) {
        ll n = j - i;
        if(i == 2) cout << n << endl;
        else cout << n * (n-1ll) / 2ll;
    }
    else cout << k-j << endl;
}


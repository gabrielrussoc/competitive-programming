#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0x3f3f3f3f;
    for(int i = 0; i < 3; i++) {
        ans = min(ans, 2*abs(i-0)*a + 2*abs(i-1)*b + 2*abs(i-2)*c); 
    }
    cout << ans << endl;
}


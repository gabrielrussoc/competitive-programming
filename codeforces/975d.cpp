#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

map<ll, int> rule;
map<pll, int> equals;
int n;
ll a, b;

int main() {
    cin >> n >> a >> b;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll x, vx, vy;
        cin >> x >> vx >> vy;
        ll goal = a * vx - vy;
        pll vel = {vx, vy};
        ans += rule[goal] - equals[vel];
        rule[goal]++;
        equals[vel]++;
    }
    cout << 2ll*ans << endl;
}


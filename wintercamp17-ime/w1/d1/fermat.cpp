#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

lint m;

lint pow(lint a, lint p) {
    if (p == 0) return 1;
    if(p % 2) return a * pow(a, p-1) % m;
    return pow((a*a)%m, p/2) % m;
}

bool isp(lint n) {
    for(lint d = 2; d * d <= n; d++)
        if(n%d == 0) return false;
    return true;
}

const int M = 250001;
lint f[M];

int main() {
    lint n;
    cin >> n >> m;
    if(isp(n) && isp(m)) {
        cout << (m-1) * (m-2) << endl;
        return 0;
    }

    vector<lint> v;
    for(lint c = 1; c < m; c++) {
        lint x = pow(c, n);
        v.push_back(x);
        f[x]++;
    }
    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    lint ans = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i; j < v.size(); j++) {
            lint a = v[i];
            lint b = v[j];
            if(i != j) ans += 2ll * f[a] * f[b] * (f[(a+b)%m]);
            else ans += f[a] * f[b] * (f[(a+b)%m]);
        }
    }
    cout << ans << endl;
    return 0;
}

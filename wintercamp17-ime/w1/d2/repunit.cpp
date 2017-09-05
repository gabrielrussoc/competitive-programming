#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

main() {
    lint n, a, b;
    cin >> n >> a >> b;
    b = 2*n - b;
    a = 2*n - a;
    lint carry;
    lint k = b - 1;
    if (k > n) k = 2*n - k + 1;
    vector<lint> v;
    carry = (k - 1) / 9;
    if (k == 0) carry = 0;
    for (lint i = b; i <= a; i++) {
        lint ans = 0;
        if (i <= n) ans = i + carry;
        else ans = 2*n - i + carry;
        carry = ans / 10;
        v.push_back(ans % 10);
    }
    for (auto it = v.rbegin(); it != v.rend(); it++) cout << *it;
    cout << endl;
}

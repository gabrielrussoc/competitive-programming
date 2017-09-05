#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

map<int, lint> mem;

int raiz(int n) {
    lint lo = 1, hi = n, ret;
    while (lo <= hi) {
        lint mid = (lo + hi) / 2;
        if (mid * mid <= n) {
            lo = mid + 1;
            ret = mid;
        } else {
            hi = mid - 1;
        }
    }
    return (int) ret;
}

lint brute(int n) {
    if (n == 1) return 0;
    lint aux = n;
    int l = raiz(n);
    int r = n - l;
    aux += brute(r);
    aux += brute(l);
    return aux;
}

lint f(int n) {
    if (n == 1) return 0;
    if (mem.find(n) != mem.end()) {
        return mem[n];
    }
    lint aux = n;
    int l = raiz(n);
    int r = n - l;
    aux += f(r);
    aux += f(l);
    mem[n] = aux;
    return aux;
}

int main() {
    int n;
    cin >> n;
    //cout << brute(n) << endl;
    cout << f(n) << endl;
    //cout << mem.size() << endl;
    return 0;
}

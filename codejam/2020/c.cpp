#include <bits/stdc++.h>
using namespace std;

struct act {
    int l, r, i;
    bool operator<(const act &o) const {
        if(l != o.l) return l < o.l;
        if(r != o.r) return r < o.r;
        return i < o.i;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<act> v(n); 
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = {l,r,i};
    }
    sort(v.begin(), v.end());

    int c = 0, j = 0;
    vector<char> ans(n);
    for(int i = 0; i < n; i++) {
        if (c <= v[i].l) {
            ans[v[i].i] = 'C';
            c = v[i].r;
        } else if (j <= v[i].l) {
            ans[v[i].i] = 'J';
            j = v[i].r;
        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << string(ans.begin(), ans.end()) << endl;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}   


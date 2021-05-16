#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<char> ans;

    int o = 0;

    for(int i = 0; i < s.size(); i++) {
        int c = s[i]-'0';
        while(o < c) {
            ans.push_back('(');
            o++;
        }
        while(o > c) {
            o--;
            ans.push_back(')');
        }
        ans.push_back(c+'0');
    }
    while(o--) ans.push_back(')');
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


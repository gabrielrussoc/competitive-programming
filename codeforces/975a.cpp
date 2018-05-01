#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<string> root;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<char> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        auto it = unique(v.begin(), v.end());
        root.insert(string(v.begin(), it));
    }
    cout << root.size() << endl;
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

unordered_map<string, int> m;
int f[300];

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(char d = 'a'; d <= 'z'; d++) f[d] = 0;
        char c = 'a';
        for(int j = 0; j < s.length(); j++) {
            if(!f[s[j]]) f[s[j]] = c++;
            s[j] = f[s[j]];
        }
        m[s]++;
    }
    ll ans = 0;
    for(auto p : m) {
        ll k = p.second;
        ans += (k * (k - 1)) / 2;
    }
    cout << ans << endl;
}
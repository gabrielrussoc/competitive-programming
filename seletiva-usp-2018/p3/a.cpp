#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        vector<char> us, ut;
        us.pb(s[0]);
        ut.pb(t[0]);
        for(int i = 1; i < (int)s.length(); i++)
            if(s[i] != s[i-1])
                us.pb(s[i]);
        for(int i = 1; i < (int)t.length(); i++)
            if(t[i] != t[i-1])
                ut.pb(t[i]);
        cout << (ut == us ? "Yes" : "No") << endl;
    }

}


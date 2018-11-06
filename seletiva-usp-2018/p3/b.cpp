#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const int A = 30;

int t, n, d;
int v[N][A], o[N][A];
string a, b;

void clear() {
    for(int j = 0; j < d; j++)
        for(int i = 0; i < A; i++)
            v[j][i] = o[j][i] = 0;
}

bool equals(int i) {
    for(int j = 0; j < A; j++)
        if(v[i][j] != o[i][j])
            return false;
    return true;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> d;
        d = min(d, n);
        cin >> a >> b;
        clear();
        for(int j = 0; j < d; j++) {
            for(int i = j; i < n; i += d) {
                v[j][a[i]-'a']++;
                o[j][b[i]-'a']++;
            }
        }
        bool ans = true;
        for(int j = 0; j < d && ans; j++)
            ans &= equals(j);
        cout << (ans ? "Yes" : "No") << endl;
    }
}


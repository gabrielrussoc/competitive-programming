#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

bool v[55];
string last;

string next() {
    if(last.length() == 1) {
        if(last[0] < 'Z') {
            string ret = " ";
            ret[0] = last[0] + 1;
            last = ret;
        }
        else {
            last = "Aa";
        }
    } else {
        string ret = "A ";
        ret[1] = last[1] + 1;
        last = ret;
    }
    return last;
}

int main() {
    int n, k;
    char s[9];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n - k + 1; i++) {
        scanf(" %s", s);
        if(strcmp(s, "NO") == 0) v[i] = false;
        else v[i] = true;
    }
    string ans[55];
    ans[0] = "A";
    last = "A";
    for(int i = 1; i < k-1; i++) {
        ans[i] = next();
    }
    for(int i = k-1; i < n; i++) {
        if(!v[i-k+1]) ans[i] = ans[i-k+1];
        else ans[i] = next();
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    putchar('\n');
}


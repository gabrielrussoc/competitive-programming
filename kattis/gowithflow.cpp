#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2505;
int n, size[N];
int words[N][N*80], ans[2][N*80];

int river(int sz) {
    int row = 0, col = 0, ret = 0;
    for(int i = 0; i < n; i++) {
        if(size[i] + col + !!col > sz) {
            col = 0;
            row++;
        }
        if(col > 0) {
            ans[row&1][col] = 1;
            if(row > 0) {
                if(words[row-1][col-1] == sz) ans[row&1][col] = max(ans[row&1][col], 1 + ans[!(row&1)][col-1]);
                if(words[row-1][col+1] == sz) ans[row&1][col] = max(ans[row&1][col], 1 + ans[!(row&1)][col+1]);
                if(words[row-1][col]   == sz) ans[row&1][col] = max(ans[row&1][col], 1 + ans[!(row&1)][col]);
            } 
            words[row][col] = sz;
            ret = max(ret, ans[row&1][col]);
        }
        col += size[i] + !!col;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        size[i] = s.length();
        mx += size[i];
    }   
    mx += n;
    int mn = *max_element(size, size+n);
    int ans = mn, len = 0;
    for(int sz = mn; sz <= mx; sz++) {
        int loc = river(sz);
        if(loc > len) {
            len = loc;
            ans = sz;
        }
    }
    cout << ans << " " << len << endl;

}


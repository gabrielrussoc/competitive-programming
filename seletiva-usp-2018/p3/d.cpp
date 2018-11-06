#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 20;
string s[N];
int t, k;

string convert(int size, int mask) {
    string ret(size, ' ');
    for(int i = 0; i < size; i++)
        ret[i] = (mask&(1<<i)) ? 'G' : 'B';
    return ret;
}

bool good(int size, int mask) {
    string guess = convert(size, mask);
    for(int l = 0; l < k; l++) {
        size_t i = 0, j = 0;
        string &cur = s[l];
        while(i < guess.length() && j < cur.length()) {
            if(guess[i] == cur[j]) j++;
            i++;
        }
        if(j < cur.length()) return false; 
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> k;
        for(int i = 0; i < k; i++) cin >> s[i];
        int size, mask;
        for(size = 1; size < N; size++)
            for(mask = 0; mask < (1<<size); mask++)
                if(good(size, mask))
                    goto done;
        done: cout << convert(size, mask) << endl;
    }
}


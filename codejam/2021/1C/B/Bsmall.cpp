#include <bits/stdc++.h>
using namespace std;

char buf[100];

bool roaring(int y) {
    sprintf(buf, "%d", y);
    string s = buf;
    int n = s.size();
    //printf("testando %d\n", y);

    for(int pref = 1; pref < n; pref++) {
        int first = stoi(s.substr(0, pref));
        //printf("first %d\n", first);
        int i = pref;
        int cnt = 1;
        bool valid = true;
        while(i < n && valid) {
            int nxt = first+cnt;
            cnt++;
            sprintf(buf, "%d", nxt);
            string t = buf;
            //printf("nxt %d\n", nxt);

            //printf("i %d\n", i);
            for(int j = 0; j < (int) t.size(); j++) {
                if(i+j >= n || s[i+j] != t[j]) {
                   // printf("ERREI em %d\n", j);
                   // printf("%c %c\n", s[i+j], t[j]);
                    valid = false;
                    break;
                }
            }

            i += t.size();
        }
        if(valid) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int Y;
        cin >> Y;

        int ans;
        for(ans = Y+1; ; ans++) {
            if(roaring(ans)) break;
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }
}



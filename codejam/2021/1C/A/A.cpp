#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end());
        auto last = unique(p.begin(), p.end());
        p.erase(last, p.end());
        n = p.size();

        vector<int> pos;
        if (n > 0) pos.push_back(p[0]-1);
        if (n > 0) pos.push_back(k-p[n-1]);

        for(int i = 0; i < n-1; i++) {
            int mid = p[i+1] - p[i] - 1;
            if (mid == 0) continue;
            if(mid%2) { 
                pos.push_back(mid/2+1);
            }
            else { 
                pos.push_back(mid/2);
            }
            pos.push_back(mid/2);
        }


        sort(pos.begin(), pos.end(), std::greater<int>());
        int d = pos[0];
        if(pos.size() > 1) d += pos[1];

        double ans = double(d) * 1. / double(k);
        cout << "Case #" << tc << ": " << ans << endl;
    }
}


#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
    cout << "M " << i << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

void swp(int i, int j) {
    if(i == j) return;
    cout << "S " << i << " " << j << endl;
    int foo;
    cin >> foo;
}

int main() {
    int t, n;
    cin >> t >> n;
    for(int tc = 1; tc <= t; tc++) {
        for(int i = 1; i < n; i++) {
            int mini = query(i, n);
            swp(i, mini);
        }
        cout << "D" << endl;
        int ans;
        cin >> ans;
        if (ans == -1) exit(1);
    }
}


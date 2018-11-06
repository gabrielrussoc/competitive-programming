#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int a[N];
int n;

string name[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int jump[] = {0,2,2,1,2,2,2,1};

bool match(int q) {
    set<int> s;
    int acc = 0;
    for(int i = 0; i < 7; i++) {
        s.insert((q+jump[i]+acc)%12);
        acc += jump[i];
    }
    for(int i = 0; i < n; i++) {
        if(s.find(a[i]%12) == s.end())
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < 12; i++) {
        if(match(i)) {
            cout << name[i] << endl;
            return 0;
        }
    }
    cout << "desafinado" << endl;
}


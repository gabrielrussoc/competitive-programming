#include <bits/stdc++.h>
using namespace std;

char ver[] = {'s', 'r', 'q', 'p'};
char hor[] = {'q', 'p', 's', 'r'};

string walk(string &s, int i, char *dir, char done1, char done2) {
    if(i == 0) return "<none>";
    s[i] = dir[s[i]-'p'];
    if(s[i] == done1 || s[i] == done2) return s;
    return walk(s, i-1, dir, done1, done2);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, aux;
        cin >> s;
        int n = s.length();
        cout << walk(aux = s, n-1, ver, 'p', 'q') << ' '; //up
        cout << walk(aux = s, n-1, ver, 's', 'r') << ' '; //down
        cout << walk(aux = s, n-1, hor, 'p', 's') << ' '; //left
        cout << walk(aux = s, n-1, hor, 'q', 'r') << '\n'; //right
    }
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

map<string, string> mp;
int n, m;
char cmd[99], ip[99];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        string name, ip;
        cin >> name >> ip;
        mp[ip] = name;
    }
    for(int i = 0; i < m; i++) {
        scanf(" %s %s", cmd, ip);
        int l = strlen(ip);
        ip[l-1] = 0;
        string s = ip;
        printf("%s %s; #%s\n", cmd, ip, mp[s].c_str());
    }
}


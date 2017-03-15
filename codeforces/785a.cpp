#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    char s[222];
    scanf("%d",&n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        scanf(" %s", s);
        if(strcmp(s, "Tetrahedron") == 0) ans += 4;
        else if(strcmp(s, "Cube") == 0) ans += 6;
        else if(strcmp(s, "Octahedron") == 0) ans += 8;
        else if(strcmp(s, "Dodecahedron") == 0) ans += 12;
        else if(strcmp(s, "Icosahedron") == 0) ans += 20;
    }
    printf("%d\n", ans);
}


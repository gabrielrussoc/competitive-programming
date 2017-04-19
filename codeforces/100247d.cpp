#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;
char s[3][N];

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < 3; i++)
        scanf(" %s", s[i]);

    for(int i = 0; i < n; i++) {
        char a = s[0][i], b = s[1][i], c = s[2][i];
        if(a == b || a == c) putchar(a);
        else putchar(b);
    }
    putchar('\n');
}
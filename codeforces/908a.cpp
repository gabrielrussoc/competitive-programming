#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

char s[55];

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool odd(char c) {
    return c == '1' || c == '3' || c == '5' || c == '7' || c == '9';
}

int main() {
    scanf(" %s", s);
    int ans = 0;
    for(int i = 0; s[i]; i++) {
        if(vowel(s[i]) || odd(s[i])) ans++;
    }
    printf("%d\n", ans);
}


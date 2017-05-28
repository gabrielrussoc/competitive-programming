#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int r;
    char s[505];
    scanf("%d",&r);
    while(r--) {
        int n;
        scanf("%d", &n);
        scanf(" %s", s);
        int o = 0;
        bool valid = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'H') o++;
            else if(s[i] == 'T') o--;
            if(o < 0 || o > 1) valid = false;
        }
        if(o > 0) valid = false;
        puts(valid ? "Valid" : "Invalid");
    }
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

void fail(){
    puts("NO");
    exit(0);
}

int main() {
    int n;
    scanf("%d",&n);
    int north = 0, south = 20000;
    int pos = north;
    char s[99];

    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d %s",&t, s);
        if(pos == north && strcmp(s, "South") != 0) fail();
        if(pos == south && strcmp(s, "North") != 0) fail();
        if(strcmp(s, "North") == 0) {
            if(pos - t < north) fail();
            pos -= t;
        } else if(strcmp(s, "South") == 0) {
            if(pos + t > south) fail();
            pos += t;
        }
    }
    if(pos != north) fail();
    puts("YES");
}

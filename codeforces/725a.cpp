#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;

char s[N];
int n;

int main() {
    scanf("%d",&n);
    scanf(" %s",s);
    bool f = false;
    int loop = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '>') f = true;
        else if(f) loop++;
    }
    f = false;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '<') f = true;
        else if(f) loop++;
    }
    printf("%d\n",n-loop);
}


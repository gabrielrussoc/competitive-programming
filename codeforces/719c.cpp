#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 212345;
char s[N];
int n, t;
int dot = 0;
set<int> lg;

void spec() {
    int carry = 1;
    for(int i = dot-1; i >= 0; i--) {
        if(s[i] == '9' && carry) {
            s[i] = '0';
            carry = 1;
        } else {
            s[i] += carry;
            carry = 0;
        }
    }
    if(carry) printf("1");
    s[dot] = 0;
    puts(s);
    exit(0);
}

int main() {
    scanf("%d %d",&n, &t);
    scanf(" %s", s);
    while(s[dot] != '.') dot++;
    for(int i = dot+1; i < n; i++) {
        if(s[i] >= '5') {
           lg.insert(i);
           break;
        }
    }
    int qt = 0;
    while(lg.size() && qt < t) {
        int i = *lg.begin();
        if(i == dot+1) spec();
        s[i-1]++;
        if(s[i-1] >= '5') lg.insert(i-1);
        s[i] = 0;
        qt++;
        lg.erase(i);
    }
    puts(s);
}


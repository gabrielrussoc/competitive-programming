#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const ll MAX = 1e18+9;

string f = "What are you doing at the end of the world? Are you busy? Will you save us?";
string pre = "What are you doing while sending \"";
string in = "\"? Are you busy? Will you send \"";
string pos = "\"?";
ll s[N];

void calc(int n, ll k) {
    if(n == 0) {
        putchar(f[k]);
        return;
    }
    ll q1 = pre.length();
    ll q2 = in.length();
    if(k < q1) putchar(pre[k]);
    else if(k < q1 + s[n-1]) calc(n-1, k-q1);
    else if(k < q1 + s[n-1] + q2) putchar(in[k-q1-s[n-1]]);
    else if(k < q1 + s[n-1] + q2 + s[n-1]) calc(n-1, k-q1-s[n-1]-q2);
    else putchar(pos[k-q1-s[n-1]-q2-s[n-1]]);
}

int main() {
    s[0] = f.length();
    ll t = pre.length() + in.length() + pos.length();
    for(int i = 1; i < N; i++) {
        if(s[i-1] >= MAX) {
            s[i] = MAX;
            continue;
        }
        s[i] = (2ll * s[i-1]) + t;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        ll k;
        scanf("%d %lld", &n, &k); k--;
        if(k >= s[n]) putchar('.');
        else calc(n, k);
    }
    putchar('\n');
}


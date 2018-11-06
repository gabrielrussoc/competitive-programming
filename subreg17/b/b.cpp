#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 33;
const int M = 1000006;
int n, t, a, x, y, b[N];
int acc[2*M+7];
vector<int> ap[2*M+7];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t >> a >> x >> y;
    for(int i = 0; i < t; i++) {
        cin >> b[i];
    }
    acc[0] = 0;
    for(int i = 0; i < 2*M; i++) {
        acc[i+1] = (acc[i] + a) % x;
        ap[acc[i+1]].pb(i);
        int nb = 0;
        for(int j = 0; j < t; j++) nb ^= !!((1<<b[j])&a);
        a >>= 1;
        a |= (1<<(n-1)) * nb;
    }
    int l, r;
    l = r = -1;
    for(int i = 0; i < 2*M; i++) {
        int cand = acc[i+1];
        auto pos = lower_bound(ap[cand].begin(), ap[cand].end(), i+y);
        if(i+1 >= y && cand == 0) {
            int ql = 0;
            int qr = i;
            if(r == -1 || qr < r) {
                r = qr; l = ql;
            } else if (qr == r) {
                if(ql < l) l = ql;
            }
        }
        if(pos != ap[cand].end()) {
            int ql = i+1;
            int qr = *pos;
            if(r == -1 || qr < r) {
                r = qr;
                l = ql;
            } else if (qr == r) {
                if(ql < l) l = ql;
            }
        }
    }
    if(l == -1) cout << "impossivel" << endl;
    else cout << l << " " << r << endl;
}


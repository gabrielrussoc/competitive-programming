#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int T = 3900;
const int N = 123;
const int inf = 1234567;
int n, t;
int d[T], b[N];

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d",&n, &t);
        for(int i = 0; i < n; i++) scanf("%d", b+i);
        for(int i = 0; i < T; i++) d[i] = inf;
        queue<int> q;
        q.push(0);
        d[0] = 0;
        while(!q.empty()) {
            int at = q.front();
            q.pop();
            for(int i = 0; i < n; i++) {
                int nx = at + b[i];
                if(nx < 0) nx = 0;
                if(nx > 3600) nx = 3600;
                if(d[nx] > d[at] + 1) {
                    d[nx] = d[at] + 1;
                    q.push(nx);
                }
            }
        }
        int tim, but;
        for(int i = t; i < T; i++) {
            if(d[i] != inf) {
                tim = i;
                but = d[i];
                break;
            }
        }
        printf("%d %d\n", but, tim - t);

    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 19;
const int M = 109;

int n, m, tot;
int f[N][M], l[N];
char s[M];

int solve(int i, bool s, int acc) {
    int done = 0;
    int j = !s ? 0 : m+1;
    int cost = 0;
    while(done < l[i]) {
        if(!s) j++;
        else j--;
        done += f[i][j];
        cost++;
    }
    if(acc + done == tot) return cost;
    return 1 + cost + min(m+1 - j + solve(i+1, 1, acc+done), j + solve(i+1, 0, acc+done));
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = n-1; i >= 0; i--) {
        scanf(" %s", s);
        for(int j = 0; j < m + 2; j++) {
            f[i][j] = s[j] - '0';
            l[i] += f[i][j];
        }
        tot += l[i];
    }

    printf("%d\n", solve(0, 0, 0));
}


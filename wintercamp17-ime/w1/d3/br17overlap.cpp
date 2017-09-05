#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int D = 25;
const int N = 500005;

int n, d, z[N], k[N];
vector<int> v[D];


int main() {
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++) {
        int dd;
        scanf("%d %d %d", z+i, k+i, &dd);
        v[dd-1].pb(i);
    }
    for(int i = 0; i < d; i++) {
        if(v[i].size() <= 1) {
            puts("NIE");
            continue;
        }
        int beg, fin;
        beg = fin = v[i][0];
        for(int j : v[i]) {
            if(z[j] > z[beg]) beg = j;
            if(k[j] < k[fin]) fin = j;
        }
        if(beg != fin && z[beg] > k[fin]) printf("ANO %d %d\n", fin+1, beg+1);
        else puts("NIE");
    }
    
}


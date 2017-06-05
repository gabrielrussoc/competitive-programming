#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int car[4], ped[4];
    for(int i = 0; i < 4; i++) car[i] = ped[i] = 0;
    for(int i = 0; i < 4; i++) {
        int l, s, r, p;
        scanf("%d %d %d %d",&l, &s, &r, &p);
        if(i == 0) {
            car[3] += l;
            car[2] += s;
            car[1] += r;
        } else if(i == 1) {
            car[0] += l;
            car[3] += s;
            car[2] += r;
        } else if(i == 2) {
            car[1] += l;
            car[0] += s;
            car[3] += r;
        } else {
            car[2] += l;
            car[1] += s;
            car[0] += r;
        }
        car[i] += l + r + s;
        ped[i] += p;
    }
    for(int i = 0; i < 4; i++) if(ped[i] && car[i]) { puts("YES"); return 0; }
    puts("NO");
}


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int X = 22;
const int Y = 22;
const int H = 11234;

char spell[169];
double memo[X][H][Y];
int visi[X][H][Y];

void parse(int &x, int &y, int &z) {
    int i = 0, j;
    while(spell[i] != 'd') i++;
    spell[i++] = 0;
    x = atoi(spell);
    j = i;
    while(isdigit(spell[i])) i++;
    if(spell[i]) {
        z = atoi(spell+i+1);
        if(spell[i] == '-') z = -z;
    }
    else z = 0;
    spell[i] = 0;
    y = atoi(spell+j);
}

double dp(int d, int q, int s) {
    if(q <= 0) return 0;
    if(d == 0) return 1;
    double &ret = memo[d][q][s];
    if(visi[d][q][s]) return ret;
    visi[d][q][s] = 1;
    for(int i = 1; i <= s; i++)
        ret += 1./double(s) * dp(d-1, q-i, s);
    return ret;
}

int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        int h, s;
        scanf("%d %d",&h, &s);
        double ans = 0;
        for(int i = 0; i < s; i++) {
            int x, y, z;
            scanf(" %s", spell);
            parse(x, y, z);
            ans = max(ans, 1-dp(x, h-z, y));
        }
        printf("Case #%d: %.20lf\n", tc, ans);
    }
}


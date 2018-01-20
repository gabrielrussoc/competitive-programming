#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct hour {
    int h, m;
    hour(){}
    hour(int _h, int _m) : h(_h), m(_m) {}
    void operator-=(int x) {
        m -= x;
        if(m < 0) {
            m += 60;
            h--;
            if(h < 0) h = 23;
        }
    }
    bool lucky() const {
        return m%10 == 7
            || m/10 == 7
            || h%10 == 7
            || h/10 == 7;
    }
};

int main() {
    int x,hh,mm;
    scanf("%d",&x);  
    scanf("%d %d", &hh, &mm);
    hour h = hour(hh, mm);
    int ans = 0;
    while(!h.lucky()) {
        ans++;
        h -= x;
    }
    printf("%d\n", ans);
     
}


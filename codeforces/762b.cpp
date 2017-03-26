#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    scanf("%d %d %d",&a, &b, &c);
    int m;
    scanf("%d",&m);
    vector<int> ps2, usb;
    for(int i = 0; i < m; i++){
        int val;
        char s[33];
        scanf("%d %s", &val, s);
        if(s[0] == 'U') usb.pb(val);
        else ps2.pb(val);
    }
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    int us = usb.size();
    int ps = ps2.size();
    int ui = 0, up = 0;
    ll price = 0;
    for(int i = 0; i < min(a, us); i++) {
        ui++;
        price += ll(usb[i]);
    }
    for(int i = 0; i < min(b, ps); i++) {
        up++;
        price += ll(ps2[i]);
    }
    int g = 0;
    while(up < ps && ui < us && g < c) {
        if(ps2[up] < usb[ui]) {
            price += ll(ps2[up]);
            up++;
        } else {
            price += ll(usb[ui]);
            ui++;
        }
        g++;
    }
    while(up < ps && g < c) {
        price += ll(ps2[up]);
        up++;
        g++;
    }
    while(ui < us && g < c) {
        price += ll(usb[ui]);
        ui++;
        g++;
    }
    printf("%d %lld\n", ui + up, price);
}


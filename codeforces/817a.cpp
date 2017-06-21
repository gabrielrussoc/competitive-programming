#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;
    int xp, yp;
    cin >> xp >> yp;

    if(((abs(xf - xi)/xp) % 2 == (abs(yf - yi)/yp) % 2) && (xf - xi) % xp == 0 && (yf - yi) % yp == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

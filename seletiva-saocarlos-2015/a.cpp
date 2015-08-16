#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;

long double pi = acos(-1);

long double solve(ll n, ll r, ll R){
	
	long double ang = pi/n;
	long double x = sqrt(r*r + R*R - 2*r*R*cos(ang));
	long double ro = (r+R+x)/2;

	return sqrt(ro*(ro-r)*(ro-R)*(ro-x));
}

int main(){
	ll n,r,R;
	cin >> n >> R >> r;
	long double ans = solve(n,r,R);
	cout << fixed;
	cout << setprecision(10) << 2*n*ans << endl;
}

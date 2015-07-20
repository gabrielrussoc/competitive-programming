#include <bits/stdc++.h>
using namespace std;
typedef  unsigned long long ll;

ll fexp(ll x, ll y, ll n){
	if(y == 0) return 1;
	if(y == 1) return x%n;

	if(y%2 == 0)
		return (fexp((x*x)%n, y/2, n))%n;

	else 
		return (x * fexp((x*x)%n, y/2, n))%n;
}

int main(){
	ll c, n, y, x, aux;

	cin >> c;

	while(c--){
		cin >> x >> y >> n;
		aux = fexp(x, y, n);
		/*while(y){
			if(y%2==0){
				x *= x;
				x %= n;
				y /= 2;
			}

			else {
				x *= aux;
				x %= n;
				y--;
			}
		}*/

		cout << aux << endl;
	}

}
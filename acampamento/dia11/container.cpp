#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <iostream>
typedef long long ll;

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,a,b,c,d;
		a = INT_MAX;
		b = INT_MAX;
		scanf("%lld",&n);
		ll tgt = (n+4)/5;
		for(ll i = 1; i*i <= tgt; i++){
			c = (tgt+i-1)/i;
			d = i;
			if(c < d){
				c = c*40 + (c+1)*4;
				d = d*8 + (d+1)*2;
			}
			else {
				d = d*40 + (d+1)*4;
				c = c*8 + (c+1)*2;
			}

			//cout << c << ' ' << d << ' ' << c*d << endl;
			if(c*d < a*b)
				a = c, b = d;
			if(c*d == a*b)
				if(abs(c-d) < abs(a-b))
					a = c, b = d;
		}
		if(a < b) swap(a,b);
		printf("%lld X %lld = %lld\n",a,b,a*b);
	}
}
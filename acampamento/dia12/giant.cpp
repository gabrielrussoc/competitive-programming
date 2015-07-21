#include <cstdio>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;


ll ceil(ll a, ll b){
	return (a+b-1)/b;
}

int main(){
		
	ll a,b,c,d,p,rh,rv,sh,sv;

	ll n;
	while(scanf("%lld %lld %lld %lld",&rh,&rv,&sh,&sv) != EOF){


		scanf("%lld",&n);
		ll ans = LLONG_MAX;
		for(int i = 0; i < n; i++){
			scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&p);

			ll h, v,h1,v1;
			h = ceil(rh,a);
			v = ceil(rv,b);
			h1 = ceil(sh,c);
			v1 = ceil(sv,d);
			ans = min(ans,p*max(h,h1)*max(v,v1));

			h = ceil(rh,b);
			v = ceil(rv,a);
			h1 = ceil(sh,d);
			v1 = ceil(sv,c);
			ans = min(ans,p*max(h,h1)*max(v,v1));
		}

		printf("%lld\n",ans);
	}


}
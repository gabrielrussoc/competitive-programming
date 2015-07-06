#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 1000000

using namespace std;

int n, t;
vector<int> fib;
vector<int>::iterator it;

int main(){

	fib.push_back(1);
	fib.push_back(2);
	for(int i = 2; i < 45; i++)
		fib.push_back(fib[i-1] + fib[i-2]);

	scanf("%d",&t);

	int c = 1;
	while(c <= t){
	
		long long ans = 1;
		scanf("%d",&n);

		for(int i = 0; i < n; i++){
			int a, b = 0;
			scanf("%d",&a);
			while(a){
				it = upper_bound(fib.begin(),fib.end(),a);
				--it;
				b++;
				a -= *it; 	
			}
			ans *= b;			
		}

		printf("Case %d: %lld\n",c++,ans);
	}
	
	


}

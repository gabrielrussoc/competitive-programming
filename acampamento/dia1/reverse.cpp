#include <cstdio>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);

	while(n > 0){
		int a,b,a1,b1;
		scanf("%d %d",&a,&b);
		int ra, rb;
		ra = rb = 0;
		
		int ta,tb;
		ta = tb = 1;
		a1 = a;
		b1 = b;

		while(a1 >= 10){
			ta *= 10;
			a1 = a1/10;
		}

		while(b1 >= 10){
			tb *= 10;
			b1 = b1/10;
		}
		
		for(int i = ta; a > 0; i /= 10){
			ra += (a%10)*i;
			a = a/10;
		}

		for(int i = tb; b; i /= 10){
			rb += (b%10)*i;
			b = b/10;
		}

		int ans = ra+rb;
		int rans = 0;
		int ans1;
		ans1 = ans;
		int tans = 1;	

		while(ans1 >= 10){
			tans *= 10;
			ans1 = ans1/10; 		
		}
		
		
		for(int i = tans; ans; i /= 10){
			rans += (ans%10)*i;
			ans = ans/10; 
		}
		printf("%d\n",rans);
		n--;
	}

}

#include <cstdio>

int main(){
	
	int n,a,b;
	scanf("%d",&n);
	n--;
	scanf("%d",&a);
	int ans = 1, max = 1;
	while(n--){
		scanf("%d",&b);
		if(b == a){
			ans++;
			if(ans > max)
				max = ans;
		}
		else
			ans = 1;
		a = b;
	}

	printf("%d\n",max);

}
#include <cmath>
#include <algorithm>
#include <cstdio>
#define MAX 200009

using namespace std;

int main(){

	int n, m, a[MAX], b[MAX], sa, sb, ans_a, ans_b, ans;

	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);

	scanf("%d",&m);
	for(int i = 0; i < m; i++)
		scanf("%d",&b[i]);

	sort(a,a+n);
	sort(b,b+m);

	int d,lo,hi,mid;

	ans_a = n*3;
	ans_b = m*3;
	ans = ans_a - ans_b;

	for(int i = 0; i < n; i++){
		d = a[i];

		lo = 0;
		hi = m-1;

		while(hi != lo){
			mid = (hi+lo)/2;

			if(b[mid] > d)
				hi = mid;
			else
				lo = mid + 1;

		}
		if(b[hi] > d)
			sb = 2*hi + 3*(m-hi);
		else
			sb = 2*m;

		lo = 0;
		hi = n-1;

		while(hi != lo){
			mid = (hi+lo)/2;

			if(a[mid] > d)
				hi = mid;
			else
				lo = mid + 1;

		}

		if(a[hi] > d)
			sa = 2*hi + 3*(n-hi);
		else
			sa = 2*n;

		if(sa - sb > ans){
			ans = sa - sb;
			ans_a = sa;
			ans_b = sb;
		} else if(sa - sb == ans){
			if(sa > ans_a){
				ans_a = sa;
				ans_b = sb;
			}
		}
	}

	for(int i = 0; i < m; i++){
		d = b[i];

		lo = 0;
		hi = m-1;

		while(hi != lo){
			mid = (hi+lo)/2;

			if(b[mid] > d)
				hi = mid;
			else
				lo = mid + 1;

		}
		if(b[hi] > d)
			sb = 2*hi + 3*(m-hi);
		else
			sb = 2*m;

		lo = 0;
		hi = n-1;

		while(hi != lo){
			mid = (hi+lo)/2;

			if(a[mid] > d)
				hi = mid;
			else
				lo = mid + 1;

		}

		if(a[hi] > d)
			sa = 2*hi + 3*(n-hi);
		else
			sa = 2*n;

		if(sa - sb > ans){
			ans = sa - sb;
			ans_a = sa;
			ans_b = sb;
		} else if(sa - sb == ans){
			if(sa > ans_a){
				ans_a = sa;
				ans_b = sb;
			}
		}

	}

	

	printf("%d:%d\n",ans_a,ans_b);
	
	return 0;
}
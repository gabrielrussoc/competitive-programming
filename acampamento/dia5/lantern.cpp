#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, l, v[1001];
	double max, dist;
	scanf("%d%d", &n, &l);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	max = 0;
	for(int i=1; i<n; i++){
		dist = v[i] - v[i-1];
		dist/=2;
		if(dist > max) max = dist;
	}
	dist = v[0];
	if(dist > max) max = dist;
	dist = l - v[n-1];
	if(dist > max) max = dist;

	printf("%.10lf\n", max);
}
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 10000

using namespace std;

bool road[MAX];

int main(){
	int n, m, a, b;

	cin >> n >> m;
	memset(road, 0, sizeof road);

	while(m--){
		cin >> a >> b;
		road[a] = road[b] = true;
	}

	printf("%d\n", n-1);

	int i = 1;
	while(road[i])
		i++;

	for(int j = 1; j <= n; j++){
		if(j != i)
			cout << i << " " << j << endl;
	}
}
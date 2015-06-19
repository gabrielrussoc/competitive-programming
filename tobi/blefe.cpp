#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

int main(){
	
	set<int> A,B;

	int n,m;
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		A.insert(a);
	}

	for(int i = 0; i < m; i++){
		int b;
		scanf("%d",&b);
		if(A.find(b) != A.end()){
			B.insert(b);
			continue;
		}

		set<int>::iterator it;
		for(it = B.begin(); it != B.end(); it++)
			if(B.find(b - *it) != B.end())
				break;

		if(it == B.end()){
			printf("%d\n",b);
			return 0;
		}

		B.insert(b);
	}

	printf("sim\n");
}
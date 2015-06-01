#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	
	queue<int> q;
	int t;

	scanf("%d",&t);

	while(t--){

		int n, k;
		scanf("%d %d",&n,&k);
		int a;

		for(int i = 0; i < pow(2,n); i++){
			scanf("%d",&a);
			q.push(a);
		}

		while(q.size() > 1){

			int c1, c2;

			c1 = q.front();
			q.pop();
			c2 = q.front();
			q.pop();

			if(c2 >= c1){
				int s = c2;
				c2 -= c1;
				c2 = min(s,c2+k);
				q.push(c2);
			}
			else{
				int s = c1;
				c1 -= c2;
				c1 = min(s,c1+k);
				q.push(c2);
			}
		}

		printf("%d\n",q.front());

	}

}
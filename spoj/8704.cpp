#include <cstdio>
#include <queue>
#include <vector>

#define pb push_back

using namespace std;

int main(){
	
	vector<int> gol;
	queue<int> q;
	int m, n;

	for(int i = 0; i < 15; i++){
		scanf("%d %d",&m,&n);
		gol.pb(m);
		gol.pb(n);
	}

	for(int i = 0; i < 16; i++)
		q.push(i);

	while(q.size() > 1){

		int a, b;
		a = q.front();
		q.pop();
		b = q.front();
		q.pop();

		if(gol[0] > gol[1])
			q.push(a);
		else
			q.push(b);

		gol.erase(gol.begin(),gol.begin()+2);

	}

	int ans = q.front();

	printf("%c\n",ans + 'A');


}
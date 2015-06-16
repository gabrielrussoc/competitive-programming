#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair <int, int> > pq; 

int main(){
	
	int n, l;
	int lig[1000007];
	int v[1005] = {0};
	scanf("%d %d",&n,&l);

	for(int i = 0; i < l; i++)
		scanf("%d",&lig[i]);

	if(l < n){
		for(int i = 0; i < n; i++)
			printf("%d %d\n",i+1,i < l ? 1 : 0);
	}
	else{ 
		for(int i = 0; i < n; i++){
			pq.push(make_pair(-lig[i],-i));
			v[i]++;
		}

		for(int i = n; i < l; i++){
			pair<int, int> aux;
			aux = pq.top();
			pq.pop();
			pq.push(make_pair(-lig[i]+aux.first,aux.second));
			v[-aux.second]++;
		}

		for(int i = 0; i < n; i++)
			printf("%d %d\n",i+1,v[i]);
	}




}
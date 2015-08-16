#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

int cost[30][30];
string s;

vector<pii> adj[27];
int d[27];

int solve(int ini, int fim){
	set<pii> pq;
	set<pii>::iterator it;
	d[ini] = 0;
	pq.insert(mp(0, ini));

	while(pq.size()){
		it = pq.begin();
		int v = it->second;
		pq.erase(it);

		if(v == fim) return d[fim];

		for(int i = 0; i < adj[v].size(); i++){
			int w = adj[v][i].first;
			int u = adj[v][i].second;
			if(d[u] > d[v] + w){
				d[u] = d[v] + w;
				pq.insert(mp(d[u], u));
			}
		}

	}
		  return INT_MAX;
}



int main(){
	

	int a;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			scanf("%d", &a);
			if(i != j)
				adj[i].pb(mp(a,j));
			else
				adj[i].pb(mp(0,j));
		}
	}



	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(i == j) cost[i][j] = 0;
			else {
				for(int i = 0; i < 27; i++)
		 			d[i] = INT_MAX;
				cost[i][j] = solve(i,j);
			}
		}
	}	

	
	cin >> s;
	int k = s.length();
	long long ans = 0;
	for(int p = 0; p < k/2; p++){
		int mini = 10000007;
		
		int a, b;
		a = s[p] - 'a';
		b = s[k-p-1] -'a' ;

		for(int i = 0; i < 26; i++)
			mini = min(mini, cost[a][i] + cost[b][i]);

		ans += mini;		
	}
	cout << ans << endl;
}

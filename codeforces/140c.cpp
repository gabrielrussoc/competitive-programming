#include <set>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

bool comp(int i, int j){
	return i > j;
}

int main(){
	
	set<pair<int,int> > s;
	map<int,int> f;
	int m[100005][5];
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		int r;
		scanf("%d",&r);
		if(!f.insert(make_pair(r,1)).second) 
			f[r]++;
	}

	map<int,int>::iterator it;
	for(it = f.begin(); it != f.end(); it++){
		s.insert(make_pair(-(it -> second), it -> first));
	}


	int ans = 0;
	set<pair<int,int> >::iterator it2;
	while(s.size() >= 3){
		pair<int,int> a,b,c;
		it2 = s.begin();
		a = *it2;
		s.erase(it2);
		it2 = s.begin();
		b = *it2;
		s.erase(it2);
		it2 = s.begin();
		c = *it2;
		s.erase(it2);
		m[ans][0] = a.second;
		m[ans][1] = b.second;
		m[ans][2] = c.second;
		a.first++;
		b.first++;
		c.first++;
		if(a.first) s.insert(a);
		if(b.first) s.insert(b);
		if(c.first) s.insert(c);
		ans++;
	}

	printf("%d\n",ans);
	for(int i = 0; i < ans; i++){
		sort(m[i],m[i]+3,comp);
		printf("%d %d %d\n",m[i][0],m[i][1],m[i][2]);
	}

}
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string in[105][3];
int freqart[38], freqnick[38];

void clear(){

	for(int i = 0; i < 38; i++){
		freqnick[i] = freqart[i] = 0;
	}

}

int main(){
	
	int k,n,m;
	char s1[25], s2[25];
	scanf("%d",&k);
	for(int i = 0; i < k; i++){
		scanf("%s %s",s1,s2);
		in[i][0] = s1;
  		in[i][1] = s2;
	}

	int maxans, ind;
	maxans = -1;
	for(int p = 0; p < k; p++){
		cin >> n >> m;
		char c;
		clear();
		int x = in[p][0].length();
		for(int i = 0; i < x; i++){
			char y = in[p][0][i];
			if(y-'a' >= 0 && y-'a' <= 25)
				freqnick[y-'a']++;
			else
				freqnick[y-'0'+26]++;

		}

		x = in[p][1].length();
		for(int i = 0; i < x; i++){
			char y = in[p][1][i];
			if(y-'a' >= 0 && y-'a' <= 25)
		    	freqnick[y-'a']++;
		    else
		 	   freqnick[y-'0'+26]++;
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf(" %c",&c);
				if(c-'a' >= 0 && c-'a' <= 25)
			   		freqart[c-'a']++;
				else
					freqart[c-'0'+26]++;	
			}
		}
		int ans = 2000000000;
		for(int i = 0; i < 38; i++)
			if(freqnick[i])
				ans = min(ans,freqart[i]/freqnick[i]);
				
		if(ans == 2000000000) ans = 0;
		if(ans > maxans){
			maxans = ans;
			ind = p;
		}
	}
	cout << in[ind][0] << ' ' << in[ind][1] << endl;

}


#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

struct guy {
	int id;
	char st;
} p[1000005];

bool comp(guy i, guy j) {
	if(i.st < j.st) 
		return true;
	else if(i.st == j.st) {
		if(i.id < j.id)
			return true;
		else
			return false;
	} else
		return false;
}

int bb(int lo, int hi, char c, int l){
	int mid = (hi + lo)/2;

	if(hi == lo){
		if(p[hi].id > l)
			return hi;
		else
			return -1;
	}

	if(p[mid].st > c)
		return bb(lo,mid-1,c,l);
	else if(p[mid].st < c)
		return bb(mid,hi,c,l);
	else{
		if(p[mid].id < l)
			return bb(mid+1,hi,c,l);
		else
			return bb(lo,mid,c,l);
	}


}

int main(){
	
	char input[1000005];

	scanf("%s",input);
	int t = strlen(input);

	for(int i = 0; i < t; i++){
		p[i].id = i;
		p[i].st = input[i];
	}

	sort(p,p+t,comp);

	int q;
	scanf("%d",&q);
	char ss[105],at;

	while(q){

		scanf("%s",ss);
		int k = strlen(ss);
		int flag = 0;
		int f,l,pos;

		for(int j = 0; j < k && !flag; j++){
			at = ss[j];

			if(j == 0)
				f = l = bb(0,t-1,at,-1);

			else if(l>=0){
				pos = bb(l+1,t-1,at,l);

				l = pos;
			}
			else
				flag = 1;

			printf("Achei %c em %d\n",at,l);
		}

		if(!flag)
			printf("Matched %d %d\n",f,l);
		else
			printf("Not matched\n");

		q--;
	}


	return 0;
}
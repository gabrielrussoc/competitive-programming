#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	
	int a,b,c;
	int h,l;
	cin >> a >> b >> c >> h >> l;	

	if(a <= h && b <= l)
		cout << "S";
	else if(b <= h && a <= l)
		cout << "S";
	else if(a <= h && c <= l)
		cout << "S";
	else if(c <= h && a <= l)
		cout << "S";
	else if(b <= h && c <= l)
		cout << "S";
	else if(c <= h && b <= l)
		cout << "S";
	else
		cout << "N";

	cout << endl;

}
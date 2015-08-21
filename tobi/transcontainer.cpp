#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int a,b,c,x,y,z;
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	
	int ans = (x/a) * (y/b) * (z/c);
	cout << ans << endl;

}

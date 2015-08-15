#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
typedef long long ll;

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    if(n == 1)
        cout << '1' << endl;
    else {
        if(n-m < m)
            cout << m-1 << endl;
        else
            cout << m+1 << endl;
    }


}
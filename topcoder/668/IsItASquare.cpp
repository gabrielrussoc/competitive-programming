// BEGIN CUT HERE
// PROBLEM STATEMENT
// It's a bird! It's a plane! No, it's a square in a plane! Wait, is it really a square?


There are four distinct points in the plane.
You are given their coordinates in the vector <int>s x and y:
for each i between 0 and 3, inclusive, there is a point at (x[i], y[i]).


Return "It's a square" (quotes for clarity) if the four points are the vertices of a square.
Otherwise, return "Not a square".

DEFINITION
Class:IsItASquare
Method:isSquare
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string isSquare(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain 4 elements.
-y will contain 4 elements.
-Each element of x will be between 0 and 10,000, inclusive.
-Each element of y will be between 0 and 10,000, inclusive.
-The four points described by x and y will be distinct.


EXAMPLES

0)
{0, 0, 2, 2}
{0, 2, 0, 2}

Returns: "It's a square"



1)
{0, 1, 5, 6}
{1, 6, 0, 5}

Returns: "It's a square"

Note that the sides of the square do not have to be parallel to the coordinate axes.
Also note that the order in which the points are given does not have to be the same as the order in which you would encounter them when following the boundary of the square.

2)
{0, 0, 7, 7}
{0, 3, 0, 3}

Returns: "Not a square"



3)
{0, 5000, 5000, 10000}
{5000, 0, 10000, 5000}

Returns: "It's a square"



4)
{1, 2, 3, 4}
{4, 3, 2, 1}

Returns: "Not a square"



5)
{0, 5, 3, 8}
{0, 0, 4, 4}

Returns: "Not a square"



// END CUT HERE
#line 83 "IsItASquare.cpp"
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
class IsItASquare {
	public:
	string isSquare(vector <int> x, vector <int> y) {
            vector<pii> p;
            for(int i = 0; i < 4; i++)
                p.push_back(make_pair(x[i],y[i]));
            sort(p.begin(),p.end());
            for(int i = 0; i < 4; i++){
                x[i] = p[i].first;
                y[i] = p[i].second;
            }
            long long ac = (x[0]-x[3])*(x[0]-x[3]) + (y[0]-y[3])*(y[0]-y[3]);
            long long bd = (x[1]-x[2])*(x[1]-x[2]) + (y[1]-y[2])*(y[1]-y[2]);
            long long esc = (x[0]-x[3])*(x[1]-x[2]) + (y[0]-y[3])*(y[1]-y[2]);
            string ans;
            if(ac == bd && !esc)
                ans = "It's a square";
            else
                ans = "Not a square";
            return ans;
	}
};

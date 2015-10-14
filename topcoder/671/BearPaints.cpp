// BEGIN CUT HERE
// PROBLEM STATEMENT
// Limak is a little polar bear.
Today he found two things in the snow: a bucket of blue paint and a white rectangular grid with W times H square cells.

Limak is going to paint some (possibly even all) cells blue.
He wants to do it in such a way that the blue cells will form a completely filled blue rectangle.
He has enough paint for M cells.
What is the largest possible area of a blue rectangle he can paint?

DEFINITION
Class:BearPaints
Method:maxArea
Parameters:int, int, long long
Returns:long long
Method signature:long long maxArea(int W, int H, long long M)


CONSTRAINTS
-W and H will be between 1 and 10^6, inclusive.
-M will be between 1 and 10^12, inclusive.


EXAMPLES

0)
3
5
14

Returns: 12

Limak has a grid that is W = 3 cells wide and H = 5 cells tall.
He doesn't have enough paint to color all 15 cells.
He also cannot color just 14 or 13 cells in a way that would produce a blue rectangle.
The best he can do is to color four consecutive rows blue.
This will produce a blue rectangle.
Its area is 12 squares.

1)
4
4
10

Returns: 9

Here the best solution is to paint a rectangle of size 3 times 3 blue.
(A square is a valid rectangle.)

2)
1000000
12345
1000000000000

Returns: 12345000000

Limak has more than enough paint to make whole grid blue.

3)
1000000
1000000
720000000007

Returns: 720000000000

Limak's grid is a square with side 10^6.
Limak can paint a rectangle of size 800,000 times 900,000.

4)
1000000
1000000
999999999999

Returns: 999999000000



// END CUT HERE
#line 80 "BearPaints.cpp"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class BearPaints {
	public:
	long long maxArea(int W, int H, long long M) {
	    long long w,h;
            w = W, h = H;
            if(M >= w*h) return w*h;
            long long ans = 0;
            for(long long i = 1; i <= W; i++){
                long long lo, hi;
                lo = 0, hi = H;
                while(lo != hi){
                    long long mid = (lo+hi+1)/2;
                    if(i*mid <= M) lo = mid;
                    else hi = mid-1;
                }
                if(lo*i > ans) ans = lo*i;
            }
            return ans;
	}
};

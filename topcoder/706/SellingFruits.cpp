#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SellingFruits {
public:
    int maxDays( int x, int f, int d, int p ) {
        ll now = min(f, d / x);
        ll left = ll(d) - ll(x) * ll(f);
        if(left <= 0) return now;
        return now + left/(x + p);
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x                     = 3;
			int f                     = 5;
			int d                     = 100;
			int p                     = 10;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 2;
			int f                     = 17;
			int d                     = 20;
			int p                     = 1;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 1;
			int f                     = 97;
			int d                     = 98;
			int p                     = 1;
			int expected__            = 97;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 16;
			int f                     = 4;
			int d                     = 8;
			int p                     = 2;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 17;
			int f                     = 1;
			int d                     = 2000000000;
			int p                     = 4;
			int expected__            = 95238095;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 1;
			int f                     = 1996245611;
			int d                     = 1999990159;
			int p                     = 123;
			int expected__            = 1996275808;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 15000000;
			int f                     = 100;
			int d                     = 2000000000;
			int p                     = 1;
			int expected__            = 133;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int x                     = 1;
			int f                     = 1000000000;
			int d                     = 2000000000;
			int p                     = 1000000000;
			int expected__            = 1000000000;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int x                     = ;
			int f                     = ;
			int d                     = ;
			int p                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x                     = ;
			int f                     = ;
			int d                     = ;
			int p                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int x                     = ;
			int f                     = ;
			int d                     = ;
			int p                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SellingFruits().maxDays(x, f, d, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

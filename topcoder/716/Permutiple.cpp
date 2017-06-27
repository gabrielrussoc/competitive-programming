#include <bits/stdc++.h>
using namespace std;

class Permutiple {
public:

    bool mult(int x, string s) {
        if(s[0] == '0') return false;
        int y = stoi(s);
        return y % x == 0 && y != x;
    }

    string isPossible( int x ) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        do {
            if (mult(x, s)) return "Possible";
        } while(next_permutation(s.begin(), s.end()));
        return "Impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x                     = 142857;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 14;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 1035;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 1000000;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 100035;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 4;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int x                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Permutiple().isPossible(x);
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

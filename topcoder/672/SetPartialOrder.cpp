#include <bits/stdc++.h>
using namespace std;

class SetPartialOrder {
public:
    string compareSets( vector <int> a, vector <int> b ) {
        sort(a.begin(), a.end());
        int freq[105];
        for(int i = 0; i < 105; i++) freq[i] = 0;
        for(int i = 0; i < a.size(); i++) freq[a[i]]++;
        int cont = 0;
        for(int i = 0; i < b.size(); i++)
            if(freq[b[i]]) cont++;
        if(a.size() == b.size() && cont == a.size())
            return "EQUAL";
        if(cont == a.size())
            return "LESS";
        if(cont == b.size())
            return "GREATER";
        return "INCOMPARABLE";
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
			int a[]                   = {1, 2, 3, 5, 8};
			int b[]                   = {8, 5, 1, 3, 2};
			string expected__         = "EQUAL";

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {2, 3, 5, 7};
			int b[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			string expected__         = "LESS";

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {2, 4, 6, 8, 10, 12, 14, 16};
			int b[]                   = {2, 4, 8, 16};
			string expected__         = "GREATER";

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {42, 23, 17};
			int b[]                   = {15, 23, 31};
			string expected__         = "INCOMPARABLE";

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SetPartialOrder().compareSets(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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

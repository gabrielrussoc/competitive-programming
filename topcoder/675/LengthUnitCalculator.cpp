#include <bits/stdc++.h>
using namespace std;

class LengthUnitCalculator {
public:
    double calc( int amount, string fromUnit, string toUnit ) {
        if(fromUnit.compare("ft") == 0){
            if(!toUnit.compare("ft")) return amount;
            else if(!toUnit.compare("in")) return amount*12;
            else if(!toUnit.compare("yd")) return (double) amount/3;
            return (double) amount/5280;
        }
        else if(!fromUnit.compare("yd")){
            if(!toUnit.compare("ft")) return 3*amount;
            else if(!toUnit.compare("in")) return amount*36;
            else if(!toUnit.compare("mi")) return (double) amount/1760;
            return (double) amount;
        
        }
        else if(!fromUnit.compare("mi")){
            if(!toUnit.compare("ft")) return 5280*amount;
            else if(!toUnit.compare("in")) return amount*63360;
            else if(!toUnit.compare("yd")) return (double) amount*1760;
            return (double) amount;
        }
        else {
            if(!toUnit.compare("ft")) return (double) amount/12;
            else if(!toUnit.compare("mi")) return (double) amount/63360;
            else if(!toUnit.compare("yd")) return (double) amount/36;
            return (double) amount;
        }
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int amount                = 1;
			string fromUnit           = "mi";
			string toUnit             = "ft";
			double expected__         = 5280.0;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int amount                = 1;
			string fromUnit           = "ft";
			string toUnit             = "mi";
			double expected__         = 1.893939393939394E-4;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int amount                = 123;
			string fromUnit           = "ft";
			string toUnit             = "yd";
			double expected__         = 41.0;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int amount                = 1000;
			string fromUnit           = "mi";
			string toUnit             = "in";
			double expected__         = 6.336E7;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int amount                = 1;
			string fromUnit           = "in";
			string toUnit             = "mi";
			double expected__         = 1.5782828282828283E-5;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int amount                = 47;
			string fromUnit           = "mi";
			string toUnit             = "mi";
			double expected__         = 47.0;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int amount                = ;
			string fromUnit           = ;
			string toUnit             = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int amount                = ;
			string fromUnit           = ;
			string toUnit             = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int amount                = ;
			string fromUnit           = ;
			string toUnit             = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = LengthUnitCalculator().calc(amount, fromUnit, toUnit);
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

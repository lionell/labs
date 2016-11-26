//
// Created by lionell on 4/4/15.
//

#include "testlib.h"
#include <ctime>

void Tester::add(BasicTest* test) {
    tests.push_back(test);
}
void Tester::run_all_tests() {
    std::cout << "****RUNNING ALL TESTS****" << std::endl;
    clock_t time = clock();
    for (int i = 0; i < tests.size(); ++i) {
        std::cout << "> Test " << i + 1 << std::endl;
        tests[i]->initialize();
        tests[i]->describe();
        bool result = tests[i]->run();
        std::cout << "> Verdict: " << (result ? "OK" : "FAIL") << std::endl;
        tests[i]->finalize();
        if (i < (int)tests.size() - 1) std::cout << "##############################" << std::endl;
    }
    time = clock() - time;
    std::cout << "TESTING FINISHED in " << ((double)time/ CLOCKS_PER_SEC) << " ms.";
}
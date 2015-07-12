//
// Created by lionell on 5/23/15.
//

#include "testlib.h"
#include <iostream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "calculator.h"

using namespace std;

void Test::describe() {
    cout << "Input: " << this->input << endl;
    cout << "Expected output: " << this->output << endl;
}

bool Test::run() {
    // Scan for lexemes with lexical analyzer
    vector<Lexeme*> lexemes = scan(this->input);
    // Parse and generate Reverse Polish Notation
    vector<Token*> rpn = parse(lexemes);
    // Calculate expression written in RPN
    BigFloat answer = calculate(rpn);
    stringstream out;
    print(answer, 6, out);
    cout << "Program returned: " << out.str() << endl;
    // Cleaning dynamic memory
    for (auto& lexeme: lexemes)
        delete lexeme;
    for (auto& token: rpn)
        delete token;
    return out.str() == this->output;
}

Tester::~Tester() {
    for (auto& test: tests)
        delete test;
}

void Tester::add(Test *test) {
    this->tests.emplace_back(test);
}

void Tester::run_all_tests() {
    cout << "****RUNNING ALL TESTS****" << endl;
    clock_t time = clock();
    for (int i = 0; i < this->tests.size(); ++i) {
        cout << "> Test " << i + 1 << endl;
        this->tests[i]->describe();
        bool result = this->tests[i]->run();
        cout << "> Verdict: " << (result ? "OK" : "FAIL") << endl;
        if (i < (int)this->tests.size() - 1) std::cout << "##############################" << std::endl;
    }
    time = clock() - time;
    cout << "TESTING FINISHED in " << ((double)time / CLOCKS_PER_SEC) << " ms.";
}
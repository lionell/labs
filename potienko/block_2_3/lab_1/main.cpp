#include <bits/stdc++.h>
#include "lexer.h"
#include "parser.h"
#include "calculator.h"
#include "exceptions.h"
#include "testlib.h"

using namespace std;

string default_path = "/home/lionell/Developing/university/laboratories/block_2_3/lab_1/";
string default_input_file = "in.txt";
string default_output_file = "out.txt";

int main(int argc, char **argv) {
    try {
        if (argc < 3) throw ModeError("At least two parameters expected");
        if (strcmp(argv[1], "-m") != 0 && strcmp(argv[1], "--mode") != 0) throw ModeError("Expected '-m' or '--mode'");
        if (strcmp(argv[2], "1") == 0) {
            Tester tester;
            tester.add(new Test("1 + 2", "3.000000"));
            tester.add(new Test("1024  ^  10", "1267650600228229401496703205376.000000"));
            tester.add(new Test("-3 / (  -3  )", "1.000000"));
            tester.add(new Test("1 / 3", "0.333333"));
            tester.add(new Test("123 * 456 /  7", "8012.571428"));
            tester.add(new Test("(1 - 2) +3/7", "-0.571428"));
            tester.add(new Test("10^17 / 2^17", "762939453125.000000"));
            tester.add(new Test("333 - 999/3", "0.000000"));
            tester.add(new Test("17-(-17)/(-1)", "0.000000"));
            tester.add(new Test("12*2+2^3", "32.000000"));
            tester.run_all_tests();
        } else if (strcmp(argv[2], "2") == 0) {
            string input_file = default_input_file;
            string output_file = default_output_file;
            if (argc >= 5 && (strcmp(argv[3], "-i") == 0 || strcmp(argv[3], "--input") == 0)) input_file = argv[4];
            if (argc >= 5 && (strcmp(argv[3], "-o") == 0 || strcmp(argv[3], "--output") == 0)) output_file = argv[4];
            if (argc >= 7 && (strcmp(argv[5], "-i") == 0 || strcmp(argv[5], "--input") == 0)) input_file = argv[6];
            if (argc >= 7 && (strcmp(argv[5], "-o") == 0 || strcmp(argv[5], "--output") == 0)) output_file = argv[6];
            ifstream in(default_path + input_file);
            ofstream out(default_path + output_file);
            string input = "";
            getline(in, input);
            // Scan for lexemes with lexical analyzer
            vector<Lexeme*> lexemes = scan(input);
            // Parse and generate Reverse Polish Notation
            vector<Token*> rpn = parse(lexemes);
            // Calculate expression written in RPN
            BigFloat answer = calculate(rpn);
            print(answer, 20, out);
            // Cleaning dynamic memory
            for (auto& lexeme: lexemes)
                delete lexeme;
            for (auto& token: rpn)
                delete token;
            in.close();
            out.close();
        } else throw ModeError("Unknown mode");
    } catch(exception &e) {
        cerr << e.what();
    }
    return 0;
}
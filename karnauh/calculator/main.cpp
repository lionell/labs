#include <bits/stdc++.h>

using namespace std;

enum LexType {
    LEFT_BRACKET,
    RIGHT_BRACKET,
    NUMBER,
    FUNCTION,
    BINARY_OPERATOR,
    UNARY_OPERATOR
};

class Lexeme {
private:
    LexType _type;
    string _value;
public:
    Lexeme(LexType type, string value): _type(type), _value(value) {}
    ~Lexeme() {}
    LexType type() {
        return _type;
    }
    string value() {
        return _value;
    }
};

int get_priority(Lexeme o) {
    int result = -1;
    if (o.type() == BINARY_OPERATOR) {
        if (o.value() == "*" || o.value() == "/") result = 4;
        else if (o.value() == "+" || o.value() == "-") result = 3;
        else if (o.value() == ")") result = 1;
        else if (o.value() == "(") result = 0;
    }
    else if (o.type() == UNARY_OPERATOR) result = 2;
    return result;
}

vector<Lexeme>& lexer(string s) {
    vector<Lexeme> *result = new vector<Lexeme>;
    unsigned long i = 0;
    while (i < s.length()) {
        if (s[i] == '*' || s[i] == '/') {
            result->push_back(Lexeme(BINARY_OPERATOR, s.substr(i, 1)));
            i++;
        } else if (s[i] == '+' || s[i] == '-') {
            if (i == 0 || s[i - 1] == '(')
                result->push_back(Lexeme(UNARY_OPERATOR, s.substr(i, 1)));
            else result->push_back(Lexeme(BINARY_OPERATOR, s.substr(i, 1)));
            i++;
        } else if (s[i] == '(') {
            result->push_back(Lexeme(LEFT_BRACKET, s.substr(i, 1)));
            i++;
        } else if (s[i] == ')') {
            result->push_back(Lexeme(RIGHT_BRACKET, s.substr(i, 1)));
            i++;
        } else if (isdigit(s[i])) {
            unsigned long j = i;
            // integer part
            while (j < s.length() && isdigit(s[j])) ++j;
            if (s[j] == '.' || tolower(s[j]) == 'e') {
                // real part
                ++j;
                while (j < s.length() && isdigit(s[j])) ++j;
            }
            result->push_back(Lexeme(NUMBER, s.substr(i, j - i)));
            i = j;
        } else if (isalpha(s[i])) {
            unsigned long j = i;
            while (j < s.length() && isalpha(s[j])) ++j;
            result->push_back(Lexeme(FUNCTION, s.substr(i, j - i)));
            i = j;
        } else if (isspace(s[i])) ++i;
        else throw("Unknown lexeme");
    }
    return *result;
}

vector<Lexeme>& transform(vector<Lexeme> &lexemes) {
    vector<Lexeme> *result = new vector<Lexeme>;
    stack<Lexeme> stack1;
    for (int i = 0; i < lexemes.size(); ++i) {
        if (lexemes[i].type() == NUMBER)
            result->push_back(lexemes[i]);
        else if (lexemes[i].type() == FUNCTION || lexemes[i].type() == LEFT_BRACKET)
            stack1.push(lexemes[i]);
        else if (lexemes[i].type() == RIGHT_BRACKET) {
            while (stack1.top().type() != LEFT_BRACKET) {
                result->push_back(stack1.top()); stack1.pop();
            }
            stack1.pop();
            if (!stack1.empty() && stack1.top().type() == FUNCTION) {
                result->push_back(stack1.top()); stack1.pop();
            }
        } else if (lexemes[i].type() == BINARY_OPERATOR || lexemes[i].type() == UNARY_OPERATOR) {
            while (!stack1.empty() && get_priority(stack1.top()) >= get_priority(lexemes[i])) {
                result->push_back(stack1.top()); stack1.pop();
            }
            stack1.push(lexemes[i]);
        }
    }
    while (!stack1.empty()) {
        result->push_back(stack1.top()); stack1.pop();
    }
    return *result;
}

double evaluate(double a, double b, string o) {
    double result = 0.0;
    if (o == "+") result = a + b;
    else if (o == "-") result = a - b;
    else if (o == "*") result = a * b;
    else if (o == "/") result = a / b;
    return result;
}

double evaluate(double a, string o) {
    double result = 0.0;
    if (o == "+") result = a;
    else if (o == "-") result = -a;
    else if (o == "exp") {
        if (a < 1e-7) throw("Arithmetic error. Argument of exponent must be positive");
        result = exp(a);
    }
    return result;
}

double calculate(vector<Lexeme> rpn) {
    stack<double> stack1;
    for (int i = 0; i < rpn.size(); ++i) {
        if (rpn[i].type() != NUMBER) {
            double c = 0.0;
            if (rpn[i].type() == BINARY_OPERATOR) {
                double b = stack1.top(); stack1.pop();
                double a = stack1.top(); stack1.pop();
                c = evaluate(a, b, rpn[i].value());
            } else {
                double a = stack1.top(); stack1.pop();
                c = evaluate(a, rpn[i].value());
            }
            stack1.push(c);
        } else stack1.push(stod(rpn[i].value()));
    }
    return stack1.top();
}

vector<string> tests = {"1+2",
                        "1 + 2",
                        "2  *   2",
                        "(1 - 2)",
                        "exp(1)",
                        "exp(2 + 1)",
                        "exp(7/3)",
                        "(exp(2/1))",
                        "1 + exp(1 / 7)",
                        "-1 * (-2)",
                        "1 - (+2)",
                        "17 * exp(1)",
                        "17*(   1 + 2)",
                        "45 / exp(5)",
                        "81 / 9 / 2",
                        "exp(exp(1))",
                        "1/exp(1)",
                        "exp(2) - exp(1)",
                        "-exp(5) / (exp(1) + 1)",
                        "exp(1) + (exp(2) - 3)/2 - (exp(5) + 1) / 2"};
int main(int argv, char **argc) {
    if (argv > 2) {
        if (strcmp(argc[1], "-m") == 0 || strcmp(argc[1], "--mode") == 0) {
            if (strcmp(argc[2], "1") == 0) {
                // user mode
                string input = "";
                getline(cin, input);
                vector<Lexeme> &lexemes = lexer(input);
                vector<Lexeme> &rpn = transform(lexemes);
                double answer = calculate(rpn);
                cout << answer;
            } else if (strcmp(argc[2], "2") == 0) {
                // file mode
                if (argv > 3) {
                    ifstream in(argc[3]);
                    string input = "";
                    getline(in, input);
                    in.close();
                    vector<Lexeme> &lexemes = lexer(input);
                    vector<Lexeme> &rpn = transform(lexemes);
                    double answer = calculate(rpn);
                    cout << answer;
                } else cout << "Error. Input file expected";
            } else if(strcmp(argc[2], "3") == 0) {
                // test mode
                for (int i = 0; i < tests.size(); ++i) {
                    cout << "[Test " << i + 1 << "] Input: " << tests[i] << endl;
                    vector<Lexeme> &lexemes = lexer(tests[i]);
                    vector<Lexeme> &rpn = transform(lexemes);
                    double answer = calculate(rpn);
                    cout << "[Test " << i + 1 << "] Output: " << answer << endl;
                    cout << "******************************" << endl;
                }
            } else cerr << "Error! Invalid mode";
        } else cerr << "Error! Mode expected";
    } else {
        cout << "To run this application you should use -m or --mode with appropriate parameter" << endl;
        cout << "> 1. to run in user mode" << endl;
        cout << "> 2. to run in file mode" << endl;
        cout << "> 3. to run in test mode" << endl;
    }
    return 0;
}
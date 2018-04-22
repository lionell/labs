%{
    #include <iostream>
    #include <list>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    using namespace std;

    int global_id = 1;
    const int hash_size = 100;
    extern int yylineno;
    extern int yylex();

    void yyerror(char *s) {
        std::cerr << s << ", line " << yylineno << std::endl;
        return;
    }

    class ParserExpression{
        public:
        ParserExpression *expr, *op;
        std::string name;
        bool args, start, finish, main;
        int id;

        ParserExpression(
        std::string name,
        ParserExpression* _expr,
        ParserExpression* op,
        bool main = 0
        ) : id(global_id++), name(name), expr(_expr), op(op), args(0), start(0), finish(0), main(main) {}

        ParserExpression() : id(global_id++), name(""), expr(NULL), op(NULL), args(0), start(0), finish(0), main(0) {}

        ParserExpression(
        ParserExpression* expr,
        bool args,
        bool start,
        bool finish,
        bool main = 0
        ) : id(global_id++),expr(expr), args(args), start(start), finish(finish), main(main), op(NULL) {}

        ParserExpression(
        ParserExpression* expr,
        bool args,
        bool start,
        bool finish,
        ParserExpression* op
        ) : id(global_id++),expr(expr), args(args), start(start), finish(finish), main(0), op(op) {}

        ParserExpression(ParserExpression* e) {
            if (e == NULL) {
                name = "";
                expr = NULL;
                op = NULL;
                id = global_id++;
            } else {
                name = "";
                expr = e;
                id = global_id++;
                op = NULL;
            }
        }

        void save_to_file(string file_name) {
            ofstream myfile;
            myfile.open (file_name.c_str());
            int root = -save_to_file_helper(myfile);
            myfile << root << endl;
            myfile.close();
        }

        static string to_string(int x) {
            char buffer[33];
            sprintf(buffer, "%d", x);
            return string(buffer);
        }

        int save_to_file_helper(ofstream &file) {
            string expr_string = (expr != NULL) ? to_string(expr->save_to_file_helper(file)) : "0";
            string op_string = (op != NULL) ? to_string(op->save_to_file_helper(file)) : "0";
            string name_string = (name.length()) ? name : "NULL";
            string result = "" + to_string(id) + " " + name_string + " " + to_string((int)args) + " " +
            to_string((int)start) + " " + to_string((int)finish) + " " + to_string((int)main) +
            " " +  expr_string + " " + op_string;

            file << result << endl;

            return id;
        }

        void print(int indent=0) {

//            std::cout<< std::endl <<"printing node" << id << std::endl;
            if(args) {
                if(start) std::cout<<"(";
                expr->print(1);
                if(finish) std::cout<<")";
                else if(!main) std::cout << ", ";

                if(op != NULL) { if(main && finish) std::cout << std::endl; op->print(); }
            } else {
                if(name == "FIELD") {
                    std::cout << name << std::endl;
                    op->print();

                }
                else if (name == "HIDEN") {
                    //std::cout << std::endl;
                    if (expr) {
                        expr->print();
                    }
                    if(op != NULL) {
                        //std::cout << std::endl;
                        op->print();
                    }
                    std::cout << std::endl;

                    //op->print()
                    //return;
                }
                else {
                    std::cout << name;
                    if(name != "" && !indent) std::cout << " "; //here was " "
                    if(expr != NULL) expr->print();

                    if(op != NULL) { if(main) /*std::cout << std::endl;*/
                        op->print(); }
                }
//                if(op != NULL) { if(main) std::cout << std::endl;
//                    op->print(); }
            }
//            std::cout<< std::endl <<"end printing node" << id << std::endl;
        }
    };

    class pr : public ParserExpression {
        public:
        pr(ParserExpression* str, ParserExpression* o) {
            name = "FIELD";
            expr = str;
            op = o;
            main = true;
        }

        pr(ParserExpression* o) {name = "FIELD"; op = o; expr = NULL; main = true; }
    };

    class listPr : public ParserExpression {
        public:
        listPr(ParserExpression* list, ParserExpression* node) {
            name = "HIDEN";
            expr = list;
            op = node;
            main = true;
        }

    };

    class value : public ParserExpression {
        public: value(const std::string& text) { name = text;}
    };

    typedef struct {
        std::string str;
        ParserExpression* oper;
        ParserExpression* args;
    } YYSTYPE;

    ParserExpression* tree;

    void read_from_file(ParserExpression* expr, string file_name) {
        ifstream ifs;
        ifs.open (file_name.c_str());
        string s;
        ParserExpression* hash[hash_size];
        for(int i = 0; i < hash_size; i++) {
            hash[i] = new ParserExpression();
        }
        int root = 0;
        while(ifs.good()) {
            int id;
            string name;
            int args, finish,start,_main;
            int expr, op;
            ifs >> id;
            if (id < 0) {
                root = -id;
                break;
            }
            ifs >> name >> args >> start >> finish >> _main >> expr >> op;

            hash[id]->id = id;
            hash[id]->name = (name != "NULL") ? name : "";
            hash[id]->args = args;
            hash[id]->start = start;
            hash[id]->finish = finish;
            hash[id]->main = _main;
            hash[id]->expr = (expr) ? hash[expr] : NULL;
            hash[id]->op = (op) ? hash[op] : NULL;
        }
        expr = hash[root];
    }
%}


//for better debuging
//%error-verbose

%token NAME BYTES START TYPE FIELD PUNCHEDCARD
%token NUM ID

%type<str> NUM ID FIELD PUNCHEDCARD
%type<oper> OPS TERM ARG LIST_OP OP
%type<expr> NAME BYTES START TYPE 
%type<args> ARGS

%%

PROGRAM: OPS                            { tree = $1; }
;

OPS:    FIELD LIST_OP                     { $$ = new pr($2); }
;


LIST_OP:
LIST_OP','OP { $$ = new listPr($1, $3); }
| OP { $$ = new listPr(NULL, $1); }
;


OP: NAME'='TERM			{ $$ = new ParserExpression("NAME", NULL , $3 , true); }
|	BYTES'='TERM		{ $$ = new ParserExpression("BYTES", $3, NULL, true); }
|	START'='TERM		{ $$ = new ParserExpression("START", $3, NULL, true); }
|	TYPE'='TERM		{ $$ = new ParserExpression("TYPE", $3, NULL, true); }
;

TERM:   NUM                             { $$ = new value($1); }
|       ID                              { $$ = new value($1); }
|       '('ARGS')'                 	{ $$ = new ParserExpression($2, true, true, false, true); }
;

ARGS:                                   { }
|       ARG                             { $$ = new ParserExpression($1, true, false, true); }
|       ARG ',' ARGS                    { $$ = new ParserExpression($1, true, false, false, $3); }
//one more
;

ARG:	NUM				{ $$ = new value($1); }
|	ID				{ $$ = new value($1); }
;
%%

int main() { 
    yyparse();
    tree->save_to_file("example.txt");
    read_from_file(tree, "example.txt");
    std::cout << "Printing tree" << std::endl;
    tree->print(0);
    return 0; 
}

//
//  tree.h
//

#ifndef __calc__tree__
#define __calc__tree__

#include <string>

class TreeNode;

enum LexemType {BINARY, UNARY, NUMBER, OPEN_BRACKET, CLOSE_BRACKET};

class Lexem {
private:
    LexemType type;
    std::string value;
public:
    Lexem (LexemType type);
    Lexem (LexemType type, const std::string &value);
    Lexem (LexemType type, char value);
    LexemType getType() const;
    std::string getValue() const;
};

class Tree {
private:
    int position;
    std::string str;
    int openBracketsCount;
    Lexem *prevLexem = NULL;
    Lexem *currLexem = NULL;
    TreeNode *root = NULL;
    
    void skipEmpty();
    void readLexem();
    bool isLast() const;
    void setRightNode(TreeNode* node);
    void addBinary();
    void parse();
public:
    int calculate(const std::string& str);
    ~Tree();
};


#endif /* defined(__calc__tree__) */

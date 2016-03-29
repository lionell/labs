//
//  tree.cpp
//

#include "tree.h"
#include "tree_nodes.h"
#include <string>
#include <typeinfo>

using namespace std;

Lexem::Lexem (LexemType type):type(type),value("") {};

Lexem::Lexem (LexemType type, const std::string &value):type(type),value(value) {};

Lexem::Lexem (LexemType type, char value):type(type),value(sizeof(char), value) {};

LexemType Lexem::getType() const
{
    return this->type;
}
std::string Lexem::getValue() const
{
    return this->value;
}


bool Tree::isLast() const
{
    return this->position == this->str.length();
}

void Tree::skipEmpty()
{
    while (!this->isLast() && isspace(this->str[this->position])) this->position++;
}

void Tree::readLexem()
{
    if (this->prevLexem != NULL) delete this->prevLexem;
    this->prevLexem = this->currLexem;
    if ((this->str[this->position] >= '0') && (this->str[this->position] <= '9')) {
        string value;
        while ((this->str[this->position] >= '0') && (this->str[this->position] <= '9') && !this->isLast()) {
            value.append(sizeof(char), this->str[this->position]);
            this->position++;
        }
        this->currLexem = new Lexem(NUMBER, value);
    } else {
        switch (this->str[this->position]) {
            case '+':
            case '*':
            case '/':
            case '%':
                this->currLexem = new Lexem(BINARY, this->str[this->position]);
                break;
            case '-':
                if (this->prevLexem == NULL || this->prevLexem->getType() == OPEN_BRACKET) {
                    this->currLexem = new Lexem(UNARY);
                } else {
                    this->currLexem = new Lexem(BINARY, this->str[this->position]);
                }
                break;
            case '(':
                this->currLexem = new Lexem(OPEN_BRACKET);
                break;
            case ')':
                this->currLexem = new Lexem(CLOSE_BRACKET);
                break;
        }
        this->position++;
    }
}

void Tree::setRightNode(TreeNode *node)
{
    if (this->root == NULL) {
        this->root = node;
        return;
    }
    TreeNode *tmp = this->root;
    while (true) {
        if (typeid(*tmp) == typeid(UnaryNode)) {
            UnaryNode* unode = (UnaryNode*)tmp;
            if (unode->getChild() == NULL) {
                unode->setChild(node);
                break;
            }
            tmp = unode->getChild();
            continue;
        }
        if (typeid(*tmp) == typeid(BinaryNode)) {
            BinaryNode* bnode = (BinaryNode*)tmp;
            if (bnode->getRight() == NULL) {
                bnode->setRight(node);
                break;
            }
            tmp = bnode->getRight();
            continue;
        }
    }
}

void Tree::addBinary()
{
    BinaryNode* bnode = new BinaryNode(this->currLexem->getValue(), this->openBracketsCount);
    if (this->root == NULL || this->root->getPriority() == 0 || this->root->getPriority() >= bnode->getPriority()) {
        bnode->setLeft(this->root);
        this->root = bnode;
        return;
    }
    if (typeid(*this->root) == typeid(BinaryNode)) {
        BinaryNode *broot = (BinaryNode*)this->root;
        bnode->setLeft(broot->getRight());
        broot->setRight(bnode);
    }
}

void Tree::parse()
{
    this->skipEmpty();
    while (!this->isLast()) {
        this->readLexem();
        this->skipEmpty();
        
        switch (this->currLexem->getType()) {
            case OPEN_BRACKET:
                this->openBracketsCount++;
                break;
            case CLOSE_BRACKET:
                this->openBracketsCount--;
                break;
            case UNARY:
                this->setRightNode(new UnaryNode());
                break;
            case BINARY:
                this->addBinary();
                break;
            case NUMBER:
                this->setRightNode(new LeafNode(this->currLexem->getValue()));;
                break;
        }
    }
}

int Tree::calculate(const string& str)
{
    this->str = str;
    this->position = 0;
    this->openBracketsCount = 0;
    if (this->root != NULL) delete this->root;
    this->root = NULL;
    if (this->prevLexem != NULL) delete this->prevLexem;
    this->prevLexem = NULL;
    if (this->currLexem != NULL) delete this->currLexem;
    this->currLexem = NULL;
    this->parse();
    return this->root->calculate();
}

Tree::~Tree()
{
    if (this->root != NULL) delete this->root;
    if (this->prevLexem != NULL) delete this->prevLexem;
    if (this->currLexem != NULL) delete this->currLexem;
}
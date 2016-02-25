//
//  tree_nodes.cpp
//

#include "tree_nodes.h"
#include <string>
#include <sstream>

using namespace std;

unsigned int TreeNode::getPriority() const
{
    return this->priority;
}

TreeNode::~TreeNode() {}

LeafNode::LeafNode(const string& s)
{
    this->priority = 0;

    istringstream iss (s);
    iss >> this->value;
}

int LeafNode::calculate()
{
    return this->value;
}

UnaryNode::UnaryNode():child(NULL)
{
    this->priority = 0;
}

UnaryNode::UnaryNode(TreeNode* child):child(child)
{
    this->priority = 0;
}

UnaryNode::~UnaryNode()
{
    if (this->child != NULL) delete this->child;
}

void UnaryNode::setChild(TreeNode *child)
{
    this->child = child;
}

TreeNode* UnaryNode::getChild() const
{
    return this->child;
}

int UnaryNode::calculate()
{
    return -this->child->calculate();
}

BinaryNode::BinaryNode(const string &s, int brackets):left(NULL), right(NULL)
{
    this->extractOperator(s);
    this->setPriority(brackets);
}

BinaryNode::BinaryNode(const string &s, int brackets, TreeNode* left):left(left), right(NULL)
{
    this->extractOperator(s);
    this->setPriority(brackets);
}

BinaryNode::BinaryNode(const string &s, int brackets, TreeNode* left, TreeNode* right):left(left), right(right)
{
    this->extractOperator(s);
    this->setPriority(brackets);
}

BinaryNode::~BinaryNode()
{
    if (this->left != NULL) delete this->left;
    if (this->right != NULL) delete this->right;
}

void BinaryNode::extractOperator(const string& s)
{
    if (s.compare("+") == 0) {
        this->op = BinaryNode::PLUS;
    } else if (s.compare("-") == 0) {
        this->op = BinaryNode::MINUS;
    } else if (s.compare("*") == 0) {
        this->op = BinaryNode::MULTIPLE;
    } else if (s.compare("/") == 0) {
        this->op = BinaryNode::DIV;
    } else {
        this->op = BinaryNode::MOD;
    }
}

void BinaryNode::setPriority(int brackets)
{
    this->priority = brackets*10;
    switch (this->op) {
        case BinaryNode::PLUS:
        case BinaryNode::MINUS:
            this->priority += 1;
            break;
        default:
            this->priority += 2;
    }
}

void BinaryNode::setLeft(TreeNode *left)
{
    this->left = left;
}

TreeNode* BinaryNode::getLeft() const
{
    return this->left;
}

void BinaryNode::setRight(TreeNode *right)
{
    this->right = right;
}

TreeNode* BinaryNode::getRight() const
{
    return this->right;
}

int BinaryNode::calculate()
{
    switch (this->op) {
        case BinaryNode::PLUS:
            return this->left->calculate() + this->right->calculate();
        case BinaryNode::MINUS:
            return this->left->calculate() - this->right->calculate();
        case BinaryNode::MULTIPLE:
            return this->left->calculate() * this->right->calculate();
        case BinaryNode::DIV:
            return this->left->calculate() / this->right->calculate();
        default:
            return this->left->calculate() % this->right->calculate();
    }
}
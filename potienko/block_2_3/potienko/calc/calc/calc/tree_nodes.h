//
//  tree_nodes.h
//

#ifndef __calc__tree_nodes__
#define __calc__tree_nodes__

#include <string>

class TreeNode {
protected:
    unsigned int priority;
public:
    virtual int calculate() = 0;
    virtual ~TreeNode();
    unsigned int getPriority() const;
};

class LeafNode: public TreeNode {
private:
    int value;
public:
    LeafNode (const std::string &s);
    int calculate();
};

class UnaryNode: public TreeNode {
private:
    TreeNode* child;
public:
    UnaryNode();
    UnaryNode(TreeNode* child);
    ~UnaryNode();
    TreeNode* getChild() const;
    void setChild(TreeNode* child);
    int calculate();
};

class BinaryNode: public TreeNode {
private:
    TreeNode *left, *right;
    int op;
    static const int PLUS = 1;
    static const int MINUS = 2;
    static const int MULTIPLE = 3;
    static const int DIV = 4;
    static const int MOD = 5;
    void extractOperator(const std::string& s);
    void setPriority(int brackets);
public:
    BinaryNode(const std::string& s, int brackets);
    BinaryNode(const std::string& s, int brackets, TreeNode* left);
    BinaryNode(const std::string& s, int brackets, TreeNode* left, TreeNode* right);
    ~BinaryNode();
    void setLeft(TreeNode* left);
    TreeNode* getLeft() const;
    void setRight(TreeNode* right);
    TreeNode* getRight() const;
    int calculate();
};


#endif /* defined(__calc__tree_nodes__) */

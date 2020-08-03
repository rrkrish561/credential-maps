#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;

struct BST : public Tree {
private:
  struct TreeNode {
  private:
    TreeNode *_left;
    TreeNode *_right;
    string _key;
    string _value;
  public:
    TreeNode(string key, string value);
    string getKey();
    string getValue();
    TreeNode *getLeft();
    TreeNode *getRight();
    void setLeft(TreeNode *left);
    void setRight(TreeNode *right);
  };
  
  TreeNode *_root;
  unsigned int _size;
  bool isLowerKeyValue(string k1, string k2);
  void deleteNodes(TreeNode *currnode);
  TreeNode *getNode(string key);
  void insertNode(string key, string value);

public:
  ~BST();
  BST();
  void Insert(string key, string value);
  string Search(string key);
};

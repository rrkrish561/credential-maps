#include "Tree.h"
#include <string>
using namespace std;

class SplayTree : public Tree {
public:
  SplayTree();
  ~SplayTree();
  void Insert(string key, string value);
  string Search(string key);

private:
  struct TreeNode{
    string key;
    string value;
    TreeNode *right;
    TreeNode *left;
  };
  TreeNode *root;
  void insertHelper(TreeNode *tempRoot, TreeNode *temp);
  string searchHelper(TreeNode *tempRoot, string key);
  TreeNode *Splay(TreeNode *tempRoot, TreeNode *node);
  TreeNode *rightRotate(TreeNode *tempRoot);
  TreeNode *leftRotate(TreeNode *tempRoot);
};

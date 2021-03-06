#include "Tree.h"
#include <string>
using namespace std;

class SplayTree : public Tree {
public:
  SplayTree();
  void Insert(string key, string value);
  string Search(string key);

private:
  bool insertHelper(TreeNode *tempRoot, TreeNode *temp);
  string searchHelper(TreeNode *tempRoot, string key);
  TreeNode *Splay(TreeNode *tempRoot, TreeNode *node);
  TreeNode *rightRotate(TreeNode *tempRoot);
  TreeNode *leftRotate(TreeNode *tempRoot);
};

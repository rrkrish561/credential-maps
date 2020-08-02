#include <string>
#include "Tree.h"
using namespace std;

class SplayTree: public Tree
{
  public:
   SplayTree();
   ~SplayTree();
   void Insert(string key, string value);
   string Search(string value);
   void Delete(string value);
  private:
   void insertHelper(TreeNode* tempRoot, TreeNode* temp);
   TreeNode* Splay(TreeNode* tempRoot, TreeNode* node);
   TreeNode* rightRotate(TreeNode* tempRoot);
   TreeNode* leftRotate(TreeNode* tempRoot);
};


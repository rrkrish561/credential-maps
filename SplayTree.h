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
   
   void Splay(TreeNode* node);
};


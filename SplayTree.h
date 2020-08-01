#include <string>
using namespace std;

class SplayTree 
{
  public:
   SplayTree();
   ~SplayTree();
   void Insert();
   void Delete(string key);
   string Search(string key); 

  private:
   struct TreeNode
   {
     string _key;
     string _value;
     TreeNode* _right;
     TreeNode* _left;
   };
    
   TreeNode* _root;

};


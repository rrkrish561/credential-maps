#include <string>

using namespace std;

class Tree
{
  protected:
    struct TreeNode
    {
      string key;
      string value;
      TreeNode* right;
      TreeNode* left;
      TreeNode* parent;
    };
    TreeNode* root;

  public:
    virtual void Insert(string key, string value) = 0;
    virtual void Delete(string key) = 0;
    virtual string Search(string key) = 0;
};


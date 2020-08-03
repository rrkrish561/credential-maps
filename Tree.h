#include <string>
using namespace std;

class Tree {
  public:
    virtual void Insert(string key, string value) = 0;
    virtual string Search(string key) = 0;

  protected:
    struct TreeNode{
        string key;
        string value;
        TreeNode *right;
        TreeNode *left;
      };
    TreeNode *root;
};

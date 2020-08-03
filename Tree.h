#include <string>
using namespace std;

class Tree {
  public:
    ~Tree();
    virtual void Insert(string key, string value) = 0;
    virtual string Search(string key) = 0;
    int getSize();
    
  protected:
    struct TreeNode{
        string key;
        string value;
        TreeNode *right;
        TreeNode *left;

        TreeNode(string _key, string _value) {
          key = _key;
          value = _value;
          right = left = nullptr;
        }
      };
    TreeNode *root;
    int size;

  private:
    void deleteTree(TreeNode* tempRoot);
};

Tree::~Tree() {
  deleteTree(root);
}

void Tree::deleteTree(TreeNode* tempRoot) {
  if(tempRoot != nullptr) {
    deleteTree(tempRoot->left);
    deleteTree(tempRoot->right);
    delete tempRoot;
  }
}

int Tree::getSize() {
  return size;
}
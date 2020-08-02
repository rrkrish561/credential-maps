#include "SplayTree.h"

using namespace std;

SplayTree::SplayTree()
{
  root = nullptr;
}

void SplayTree::Insert(string key, string value)
{
  TreeNode* temp = new TreeNode();
  temp->key = key;
  temp->value = value;
  temp->right = nullptr;
  temp->left = nullptr;

  if(root == nullptr)
  {
    root = temp;
  }
  else
  {
    insertHelper(root, temp);
  }

  Splay(temp);
}

void SplayTree::insertHelper(TreeNode* tempRoot, TreeNode* temp)
{
  if(temp->value < tempRoot->value)
  {
    if(tempRoot->left == nullptr)
      tempRoot->left = temp;
    else
      insertHelper(tempRoot->left, temp);
  }
  else if(temp->value > tempRoot->value)
  {
    if(tempRoot->right == nullptr)
      tempRoot->right = temp;
    else
      insertHelper(tempRoot->right, temp);
  }

}
void SplayTree::Splay(TreeNode* node)
{
  
}

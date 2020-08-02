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

  root = Splay(root, temp);
}

void SplayTree::insertHelper(TreeNode* tempRoot, TreeNode* temp)
{
  if(temp->value < tempRoot->value)
  {
    if(tempRoot->left == nullptr)
    {
      tempRoot->left = temp;
    }
    else
      insertHelper(tempRoot->left, temp);
  }
  else if(temp->value > tempRoot->value)
  {
    if(tempRoot->right == nullptr)
    {  
      tempRoot->right = temp;
    }
    else
      insertHelper(tempRoot->right, temp);
  }
}

Tree::TreeNode* SplayTree::Splay(Tree::TreeNode* tempRoot, Tree::TreeNode* node)
{
  if(node == tempRoot || tempRoot == nullptr)
  {
    return tempRoot;
  }

  if(node->value < tempRoot->value)
  {
    if(tempRoot->left == nullptr)
      return tempRoot;

    if(node->value < tempRoot->left->value)
    {
      tempRoot->left->left = Splay(tempRoot->left->left, node);
      tempRoot->left = rightRotate(tempRoot->left);
    }
    else if(node->value > tempRoot->left->value)
    {
      tempRoot->left->right = Splay(tempRoot->left->right, node);
      tempRoot->left = leftRotate(tempRoot->left);
    }

    tempRoot = rightRotate(tempRoot);
    return tempRoot;
  }
  else
  {
    if(tempRoot->right == nullptr)
      return tempRoot;

    if(node->value > tempRoot->right->value)
    {
      tempRoot->right->right = Splay(tempRoot->right->right, node);
      tempRoot->right = leftRotate(tempRoot->right);
    }
    else if(node->value < tempRoot->right->value)
    {
      tempRoot->right->left = Splay(tempRoot->right->left, node);
      tempRoot->right = rightRotate(tempRoot->right);
    }
    tempRoot = leftRotate(tempRoot);
    return tempRoot;
  }
}

Tree::TreeNode* SplayTree::rightRotate(Tree::TreeNode* tempRoot)
{
  return nullptr;
}
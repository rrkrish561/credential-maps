#pragma once

#include <string>

class Tree {
public:
  ~Tree();
  virtual void Insert(std::string _key, std::string _value) = 0;
  virtual std::string Search(std::string _key) = 0;
  int getSize();

protected:
  struct TreeNode {
    std::string key;
    std::string value;
    TreeNode *right;
    TreeNode *left;

    TreeNode(std::string _key, std::string _value) {
      key = _key;
      value = _value;
      right = left = nullptr;
    }
  };
  TreeNode *root;
  int size;

private:
  void deleteTree(TreeNode *tempRoot);
};